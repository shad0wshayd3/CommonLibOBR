#pragma once

#include "UE/F/FDefaultAllocator.h"
#include "UE/F/FDefaultBitArrayAllocator.h"

namespace UE
{
	template <class A1 = FDefaultAllocator, class A2 = FDefaultBitArrayAllocator>
	class TSparseArrayAllocator
	{
	public:
		using ElementAllocator = A1;
		using BitArrayAllocator = A2;
	};
	static_assert(std::is_empty_v<TSparseArrayAllocator<>>);
}
