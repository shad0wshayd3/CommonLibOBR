#pragma once

#include "UE/T/TSetElement.h"
#include "UE/T/TSparseArray.h"

namespace UE
{
	template <class T, class KeyFuncs, class Allocator>
	class TSet
	{
	public:
		TSparseArray<TSetElement<T>> elements;    // 00
		std::byte                    hash[0x12];  // 38
		std::int32_t                 hashSize;    // 48
	};
	static_assert(sizeof(TSet<void*, void*, void*>) == 0x50);
}
