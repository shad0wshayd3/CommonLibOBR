#pragma once

#include "RE/F/FDefaultBitArrayAllocator.h"
#include "RE/T/TSizedDefaultAllocator.h"

namespace RE::UE
{
	template <class T = TSizedDefaultAllocator<32>, class U = FDefaultBitArrayAllocator>
	class TSparseArrayAllocator
	{
	public:
	};
	static_assert(std::is_empty_v<TSparseArrayAllocator<void*, void*>>);
}
