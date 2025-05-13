#pragma once

#include "UE/T/TMapBase.h"

namespace UE
{
	template <class T, class U, class A, class H>
	class TSortableMapBase :
		public TMapBase<T, U, A, H>
	{
	public:
	};
	static_assert(sizeof(TSortableMapBase<void*, void*, FDefaultSetAllocator, TDefaultMapHashableKeyFuncs<void*, void*, 0>>) == 0x50);
}
