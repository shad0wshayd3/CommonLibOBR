#pragma once

#include "UE/E/EName.h"
#include "UE/E/ENameCase.h"
#include "UE/F/FNameEntry.h"
#include "UE/F/FNameEntryAllocator.h"
#include "UE/F/FNameEntryHandle.h"
#include "UE/T/TInlineSetAllocator.h"
#include "UE/T/TMap.h"
#include "UE/T/TNamePoolShard.h"

namespace UE
{
	class FNamePool
	{
	public:
		static FNamePool* GetSingleton()
		{
			static REL::Relocation<FNamePool*> ptr{ ID::FNamePool::GetSingleton };
			return ptr.get();
		}

		FNameEntryId Find(EName a_name) const
		{
			return eNameToEntry[std::to_underlying(a_name)];
		}

		FNameEntry& Resolve(FNameEntryHandle a_handle) const
		{
			return entries.Resolve(a_handle);
		}

		// members
		FNameEntryAllocator entries;                                                 // 00000
		alignas(64) TNamePoolShard<ENameCase::IgnoreCase> comparisonShards[256];     // 10010
		FNameEntryId                                        eNameToEntry[703];       // 14010
		std::uint32_t                                       largestEnameUnstableId;  // 14B0C
		TMap<FNameEntryId, EName, TInlineSetAllocator<512>> entryToEName;            // 14B10
	};
	static_assert(sizeof(FNamePool) == 0x16FC0);
}
