#pragma once

#include "RE/F/FDefaultSetAllocator.h"
#include "RE/T/TDefaultMapHashableKeyFuncs.h"
#include "RE/T/TSortableMapBase.h"

namespace RE::UE
{
	template <class T, class U, class Allocator = FDefaultSetAllocator, class HashableKeyFuncs = TDefaultMapHashableKeyFuncs<T, U, 0>>
	class TMap :
		public TSortableMapBase<T, U, Allocator, HashableKeyFuncs>
	{
	public:
	};
	static_assert(sizeof(TMap<void*, void*, void*, void*>) == 0x50);
}
