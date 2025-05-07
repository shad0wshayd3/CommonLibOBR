#pragma once

#include "RE/F/FDefaultBitArrayAllocator.h"
#include "RE/T/TSizedDefaultAllocator.h"
#include "RE/T/TSparseArrayAllocator.h"

namespace RE::UE
{
	class FDefaultSparseArrayAllocator :
		public TSparseArrayAllocator<TSizedDefaultAllocator<32>, FDefaultBitArrayAllocator>
	{
	public:
	};
	static_assert(std::is_empty_v<FDefaultSparseArrayAllocator>);
}
