#pragma once

#include "UE/T/TInlineSparseArrayAllocator.h"
#include "UE/T/TSetAllocator.h"

namespace UE
{
	template <
		std::uint32_t N,
		class A = TSetAllocator<TSparseArrayAllocator<FDefaultAllocator, FDefaultAllocator>, FDefaultAllocator>,
		std::uint32_t NA = 2,
		std::uint32_t NM = 4>
	class TInlineSetAllocator
	{
		static constexpr auto NumInlineHashBuckets{ (N + NA - 1) / NA };

	public:
		using SparseArrayAllocator = TInlineSparseArrayAllocator<N, typename A::SparseArrayAllocator>;
		using HashAllocator = TInlineAllocator<NumInlineHashBuckets, typename A::HashAllocator>;
	};
}
