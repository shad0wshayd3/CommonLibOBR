#pragma once

#include "UE/E/EName.h"

namespace UE
{
	class FNameEntryId
	{
	public:
		FNameEntryId() = default;

		std::uint32_t ToUnstableInt() const
		{
			return value;
		}

		static FNameEntryId FromEName(EName a_name)
		{
			return a_name == EName::None ? FNameEntryId() : FromValidEName(a_name);
		}

		static FNameEntryId FromUnstableInt(const std::uint32_t a_value)
		{
			FNameEntryId id;
			id.value = a_value;
			return id;
		}

		static FNameEntryId FromValidEName(EName a_name);

		// members
		std::uint32_t value{ 0 };  // 00
	};
	static_assert(sizeof(FNameEntryId) == 0x04);
}
