#pragma once

#include "UE/F/FNameEntry.h"
#include "UE/F/FNameEntryHandle.h"

namespace UE
{
	class FNameEntryAllocator
	{
	public:
		FNameEntry& Resolve(FNameEntryHandle a_handle) const
		{
			return *reinterpret_cast<FNameEntry*>(blocks[a_handle.block] + alignof(FNameEntry) * a_handle.offset);
		}

		// members
		void*         lock;               // 000
		std::uint32_t currentBlock;       // 004
		std::uint32_t currentByteCursor;  // 008
		std::uint8_t* blocks[8192];       // 00C
	};
	static_assert(sizeof(FNameEntryAllocator) == 0x10010);
}
