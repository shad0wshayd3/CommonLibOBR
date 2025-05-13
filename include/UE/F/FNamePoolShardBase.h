#pragma once

#include "UE/F/FRWLock.h"

namespace UE
{
	class FNameEntryAllocator;
	class FNameSlot;

	class alignas(32) FNamePoolShardBase
	{
	public:
		// members
		mutable FRWLock      lock;
		std::uint32_t        usedSlots;
		std::uint32_t        capacityMask;
		FNameSlot*           slots;
		FNameEntryAllocator* entries;
		std::uint32_t        numCreatedEntries;
		std::uint32_t        numCreatedWideEntries;
		std::uint32_t        numCreatedWithNumberEntries;
	};
	static_assert(sizeof(FNamePoolShardBase) == 0x40);
}
