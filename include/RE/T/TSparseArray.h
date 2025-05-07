#pragma once

#include "RE/F/FDefaultBitArrayAllocator.h"
#include "RE/F/FDefaultSparseArrayAllocator.h"
#include "RE/T/TAlignedBytes.h"
#include "RE/T/TArray.h"
#include "RE/T/TBitArray.h"
#include "RE/T/TSparseArrayElementOrFreeListLink.h"

namespace RE::UE
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
