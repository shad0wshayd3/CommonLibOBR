#pragma once

#include "RE/F/FNameEntryId.h"

namespace RE::UE
{
	class FName
	{
	public:
		// members
		FNameEntryId  comparisonIndex;  // 00
		std::uint32_t number;           // 04
	};
	static_assert(sizeof(FName) == 0x08);
}
