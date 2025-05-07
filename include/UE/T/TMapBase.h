#pragma once

#include "UE/F/FPathGridPointDataArray.h"
#include "UE/T/TDefaultMapHashableKeyFuncs.h"
#include "UE/T/TSet.h"
#include "UE/T/TTuple.h"

namespace UE
{
	template <class T, class U, class Allocator, class HashableKeyFuncs>
	class TMapBase
	{
	public:
		// members
		TSet<TTuple<T, U>, HashableKeyFuncs, Allocator> pairs;  // 00
	};
	static_assert(sizeof(TMapBase<void*, FPathGridPointDataArray, FDefaultSetAllocator, TDefaultMapHashableKeyFuncs<void*, void*, 0>>) == 0x50);
}
