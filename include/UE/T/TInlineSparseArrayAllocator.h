#pragma once

#include "UE/T/TInlineAllocator.h"
#include "UE/T/TSparseArrayAllocator.h"

namespace UE
{
	template <std::uint32_t N, class A = TSparseArrayAllocator<FDefaultAllocator, FDefaultAllocator>>
	class TInlineSparseArrayAllocator
	{
	public:
		static constexpr auto InlineBitArrayDWORDs{ (N + 32 - 1) / 32 };

		using ElementAllocator = TInlineAllocator<N, typename A::ElementAllocator>;
		using BitArrayAllocator = TInlineAllocator<InlineBitArrayDWORDs, typename A::BitArrayAllocator>;
	};
}
