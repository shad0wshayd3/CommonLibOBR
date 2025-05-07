#pragma once

#include "UE/F/FDefaultBitArrayAllocator.h"
#include "UE/T/TSizedDefaultAllocator.h"

namespace UE
{
	template <class T = TSizedDefaultAllocator<32>, class U = FDefaultBitArrayAllocator>
	class TSparseArrayAllocator
	{
	public:
	};
	static_assert(std::is_empty_v<TSparseArrayAllocator<void*, void*>>);
}
