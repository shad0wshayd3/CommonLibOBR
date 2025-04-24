#include "REL/IDDB.h"
#include "REL/Module.h"
#include "REL/Version.h"

#include "REX/W32/BCRYPT.h"

namespace REL
{
	std::optional<std::string> SHA512(std::span<const std::byte> a_data)
	{
		REX::W32::BCRYPT_ALG_HANDLE algorithm;
		if (!REX::W32::NT_SUCCESS(REX::W32::BCryptOpenAlgorithmProvider(&algorithm, REX::W32::BCRYPT_SHA512_ALGORITHM))) {
			REX::ERROR("failed to open algorithm provider");
			return std::nullopt;
		}

		const stl::scope_exit delAlgorithm([&]() {
			[[maybe_unused]] const auto success = REX::W32::NT_SUCCESS(REX::W32::BCryptCloseAlgorithmProvider(algorithm));
			assert(success);
		});

		REX::W32::BCRYPT_HASH_HANDLE hash;
		if (!REX::W32::NT_SUCCESS(REX::W32::BCryptCreateHash(algorithm, &hash))) {
			REX::ERROR("failed to create hash");
			return std::nullopt;
		}

		const stl::scope_exit delHash([&]() {
			[[maybe_unused]] const auto success = REX::W32::NT_SUCCESS(REX::W32::BCryptDestroyHash(hash));
			assert(success);
		});

		if (!REX::W32::NT_SUCCESS(REX::W32::BCryptHashData(
				hash,
				reinterpret_cast<std::uint8_t*>(const_cast<std::byte*>(a_data.data())),  // does not modify contents of buffer
				static_cast<std::uint32_t>(a_data.size())))) {
			REX::ERROR("failed to hash data");
			return std::nullopt;
		}

		std::uint32_t hashLen = 0;
		std::uint32_t discard = 0;
		if (!REX::W32::NT_SUCCESS(REX::W32::BCryptGetProperty(
				hash,
				REX::W32::BCRYPT_HASH_LENGTH,
				reinterpret_cast<std::uint8_t*>(&hashLen),
				sizeof(hashLen),
				&discard))) {
			REX::ERROR("failed to get property");
			return std::nullopt;
		}

		std::vector<std::uint8_t> buffer(static_cast<std::size_t>(hashLen));
		if (!REX::W32::NT_SUCCESS(REX::W32::BCryptFinishHash(
				hash,
				buffer.data(),
				static_cast<std::uint32_t>(buffer.size())))) {
			REX::ERROR("failed to finish hash");
			return std::nullopt;
		}

		std::string result;
		result.reserve(buffer.size() * 2);
		for (const auto byte : buffer) {
			result += std::format("{:02X}", byte);
		}

		return { std::move(result) };
	}
}

namespace REL
{
	IDDB::IDDB()
	{
		const auto version = Module::get().version();
		const auto path = std::format("OBSE/Plugins/versionlib-{}.bin", version.string("-"sv));
		if (!_mmap.open(path)) {
			stl::report_and_fail(std::format("failed to open: {}", path));
		}

		_id2offset = std::span{
			reinterpret_cast<const mapping_t*>(_mmap.data() + sizeof(std::uint64_t)),
			*reinterpret_cast<const std::uint64_t*>(_mmap.data())
		};
	}

	std::size_t IDDB::id2offset(std::uint64_t a_id) const
	{
		if (_id2offset.empty()) {
			stl::report_and_fail("data is empty"sv);
		}

		const mapping_t elem{ a_id, 0 };
		const auto      it = std::lower_bound(
            _id2offset.begin(),
            _id2offset.end(),
            elem,
            [](auto&& a_lhs, auto&& a_rhs) {
                return a_lhs.id < a_rhs.id;
            });
		if (it == _id2offset.end()) {
			const auto version = Module::get().version();
			const auto str = std::format("id {} not found!\ngame version: {}"sv, a_id, version.string());
			stl::report_and_fail(str);
		}

		return static_cast<std::size_t>(it->offset);
	}
}
