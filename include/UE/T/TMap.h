#pragma once

#include "UE/F/FDefaultSetAllocator.h"
#include "UE/T/TDefaultMapHashableKeyFuncs.h"
#include "UE/T/TSortableMapBase.h"

namespace UE
{
	template <class T, class U, class Allocator = FDefaultSetAllocator, class HashableKeyFuncs = TDefaultMapHashableKeyFuncs<T, U, 0>>
	class TMap :
		public TSortableMapBase<T, U, Allocator, HashableKeyFuncs>
	{
	public:
	};
	static_assert(sizeof(TMap<void*, void*, void*, void*>) == 0x50);
}
