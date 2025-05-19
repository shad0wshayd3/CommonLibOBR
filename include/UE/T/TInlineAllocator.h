#pragma once

#include "UE/F/FDefaultAllocator.h"
#include "UE/T/TSizedInlineAllocator.h"

namespace UE
{
	template <std::uint32_t N, class A = FDefaultAllocator>
	using TInlineAllocator = TSizedInlineAllocator<N, 32, A>;

	template <std::uint32_t N, class A = FDefaultAllocator64>
	using TInlineAllocator64 = TSizedInlineAllocator<N, 64, A>;
}
