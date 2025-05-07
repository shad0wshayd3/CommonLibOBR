#pragma once

#include "RE/D/DefaultKeyFuncs.h"
#include "RE/F/FDefaultSetAllocator.h"
#include "RE/F/FSetElementId.h"
#include "RE/T/TSetElement.h"
#include "RE/T/TSizedDefaultAllocator.h"
#include "RE/T/TSizedInlineAllocator.h"
#include "RE/T/TSparseArray.h"

namespace RE::UE
{
	template <class T, class KeyFuncs, class Allocator>
	class TSet
	{
	public:
		TSparseArray<TSetElement<T>> elements;    // 00
		std::byte                    hash[0x10];  // 38
		std::int32_t                 hashSize;    // 48
	};
	static_assert(sizeof(TSet<void*, DefaultKeyFuncs<void*, 0>, FDefaultSetAllocator>) == 0x50);
}
