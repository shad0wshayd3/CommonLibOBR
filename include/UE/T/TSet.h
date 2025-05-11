#pragma once

#include "UE/D/DefaultKeyFuncs.h"
#include "UE/T/TSetElement.h"
#include "UE/T/TSparseArray.h"

namespace UE
{
	template <class T, class KeyFuncs = DefaultKeyFuncs<T>, class Allocator = FDefaultSetAllocator>
	class TSet
	{
	public:
		TSparseArray<TSetElement<T>> elements;    // 00
		std::byte                    hash[0x12];  // 38
		std::int32_t                 hashSize;    // 48
	};
	static_assert(sizeof(TSet<void*>) == 0x50);
}
