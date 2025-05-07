#pragma once

#include "UE/F/FDefaultBitArrayAllocator.h"
#include "UE/F/FDefaultSparseArrayAllocator.h"
#include "UE/T/TAlignedBytes.h"
#include "UE/T/TArray.h"
#include "UE/T/TBitArray.h"
#include "UE/T/TSparseArrayElementOrFreeListLink.h"

namespace UE
{
	template <class T, class Allocator = FDefaultSparseArrayAllocator>
	class TSparseArray
	{
	public:
		// members
		TArray<TSparseArrayElementOrFreeListLink<TAlignedBytes<sizeof(T), 0>>> data;             // 00
		TBitArray<FDefaultBitArrayAllocator>                                   allocationFlags;  // 10
		std::int32_t                                                           firstFreeIndex;   // 30
		std::int32_t                                                           numFreeIndices;   // 34
	};
	static_assert(sizeof(TSparseArray<void*>) == 0x38);
}
