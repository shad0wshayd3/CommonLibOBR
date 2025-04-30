#include "RE/S/Setting.h"

#include "RE/M/MemoryManager.h"

namespace RE
{
	bool Setting::IsManaged() const
	{
		return name && name[0] == 'S';
	}

	auto Setting::GetType() const
		-> Type
	{
		if (!name) {
			return Type::kUnknown;
		} else {
			switch (name[0]) {
				case 'b':
					return Type::kBool;
				case 'f':
					return Type::kFloat;
				case 'i':
					return Type::kSignedInteger;
				case 'r':
					return Type::kColor;
				case 'S':
				case 's':
					return Type::kString;
				case 'u':
					return Type::kUnsignedInteger;
				default:
					return Type::kUnknown;
			}
		}
	}

	const char* Setting::GetName() const
	{
		return name ? name : "";
	}

	bool Setting::GetBool() const
	{
		return data.b;
	}

	float Setting::GetFloat() const
	{
		return data.f;
	}

	std::int32_t Setting::GetSInt() const
	{
		return data.i;
	}

	std::span<const std::uint8_t, 3> Setting::GetColor() const
	{
		return std::span<const std::uint8_t, 3>{
			reinterpret_cast<const std::uint8_t(&)[3]>(*std::addressof(data.r))
		};
	}

	const char* Setting::GetString() const
	{
		return data.s ? data.s : "";
	}

	std::uint32_t Setting::GetUInt() const
	{
		return data.u;
	}

	void Setting::SetString(const char* a_value)
	{
		using func_t = decltype(&Setting::SetString);
		static REL::Relocation<func_t> func{ ID::Setting::SetString };
		func(this, a_value);
	}
}
