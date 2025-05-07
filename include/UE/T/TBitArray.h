#pragma once

#include "UE/F/FDefaultBitArrayAllocator.h"

namespace UE
{
	template <class Allocator = FDefaultBitArrayAllocator>
	class TBitArray
	{
	public:
		// members
		std::byte    allocatorInstance[0x18];  // 00
		std::int32_t numBits;                  // 18
		std::int32_t maxBits;                  // 1C
	};
	static_assert(sizeof(TBitArray<FDefaultBitArrayAllocator>) == 0x20);
}
