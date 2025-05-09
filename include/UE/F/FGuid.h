#pragma once

namespace UE
{
	class FGuid
	{
	public:
		constexpr FGuid() = default;

		explicit constexpr FGuid(std::uint32_t a_a, std::uint32_t a_b, std::uint32_t a_c, std::uint32_t a_d) :
			a(a_a), b(a_b), c(a_c), d(a_d)
		{}

		// members
		std::uint32_t a{ 0 };
		std::uint32_t b{ 0 };
		std::uint32_t c{ 0 };
		std::uint32_t d{ 0 };
	};
	static_assert(sizeof(FGuid) == 0x10);
}
