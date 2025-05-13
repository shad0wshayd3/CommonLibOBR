#pragma once

#include "UE/F/FDefaultBitArrayAllocator.h"

namespace UE
{
	template <class A = FDefaultBitArrayAllocator>
	class TBitArray
	{
	public:
		using AllocatorType = typename A::template ForElementType<std::uint32_t>;

		// members
		AllocatorType allocatorInstance;  // 00
		std::int32_t  numBits;            // 18
		std::int32_t  maxBits;            // 1C
	};
	static_assert(sizeof(TBitArray<FDefaultBitArrayAllocator>) == 0x20);
}
