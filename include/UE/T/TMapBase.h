#pragma once

#include "UE/F/FPathGridPointDataArray.h"
#include "UE/T/TDefaultMapHashableKeyFuncs.h"
#include "UE/T/TSet.h"
#include "UE/T/TTuple.h"

namespace UE
{
	template <class T, class U>
	using TPair = TTuple<T, U>;

	template <class T, class U, class A, class H>
	class TMapBase
	{
	public:
		// members
		TSet<TPair<T, U>, H, A> pairs;  // 00
	};
	static_assert(sizeof(TMapBase<void*, FPathGridPointDataArray, FDefaultSetAllocator, TDefaultMapHashableKeyFuncs<void*, void*, 0>>) == 0x50);
}
