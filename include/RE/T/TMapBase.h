#pragma once

#include "RE/F/FPathGridPointDataArray.h"
#include "RE/T/TDefaultMapHashableKeyFuncs.h"
#include "RE/T/TSet.h"
#include "RE/T/TTuple.h"

namespace RE::UE
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
