#pragma once

#include "RE/T/TMapBase.h"

namespace RE::UE
{
	template <class T, class U, class Allocator, class HashableKeyFuncs>
	class TSortableMapBase :
		public TMapBase<T, U, Allocator, HashableKeyFuncs>
	{
	public:
	};
	static_assert(sizeof(TSortableMapBase<void*, void*, void*, void*>) == 0x50);
}
