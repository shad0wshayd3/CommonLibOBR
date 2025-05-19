#pragma once

#include "UE/F/FDefaultSetAllocator.h"
#include "UE/T/TDefaultMapHashableKeyFuncs.h"
#include "UE/T/TSortableMapBase.h"

namespace UE
{
	template <class T, class U, class A = FDefaultSetAllocator, class H = TDefaultMapHashableKeyFuncs<T, U, 0>>
	class TMap :
		public TSortableMapBase<T, U, A, H>
	{
	public:
	};
	static_assert(sizeof(TMap<void*, void*>) == 0x50);
}
