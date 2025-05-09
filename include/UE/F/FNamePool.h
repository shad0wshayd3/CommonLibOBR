#pragma once

#include "UE/F/FNameEntry.h"
#include "UE/F/FNameEntryHandle.h"
#include "UE/F/FNameEntryAllocator.h"

namespace UE
{
	class FNamePool
	{
	public:
		static FNamePool* GetSingleton()
		{
			static REL::Relocation<FNamePool**> ptr{ ID::FNamePool::GetSingleton };
			return *ptr;
		}

		FNameEntry& Resolve(FNameEntryHandle a_handle) const
		{
			return entries.Resolve(a_handle);
		}

		// members
		FNameEntryAllocator entries;  // 00
	};
}
