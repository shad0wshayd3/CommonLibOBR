#pragma once

#include "UE/F/FNameEntryId.h"

namespace UE
{
	class FNameEntryHandle
	{
	public:
		FNameEntryHandle(FNameEntryId a_id) :
			block(a_id.ToUnstableInt() >> 16),
			offset(a_id.ToUnstableInt() & ((1 << 16) - 1))
		{}

		// members
		std::uint32_t block{ 0 };   // 00
		std::uint32_t offset{ 0 };  // 04
	};
	static_assert(sizeof(FNameEntryHandle) == 0x08);
}
