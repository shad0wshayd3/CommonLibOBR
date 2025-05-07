#pragma once

#include "UE/F/FDefaultBitArrayAllocator.h"
#include "UE/T/TSetAllocator.h"
#include "UE/T/TSizedDefaultAllocator.h"
#include "UE/T/TSizedInlineAllocator.h"
#include "UE/T/TSparseArrayAllocator.h"

namespace UE
{
	class FDefaultSetAllocator :
		public TSetAllocator<TSparseArrayAllocator<TSizedDefaultAllocator<32>, FDefaultBitArrayAllocator>, TSizedInlineAllocator<1, 32, TSizedDefaultAllocator<32>>, 2, 8, 4>
	{
	public:
	};
	static_assert(std::is_empty_v<FDefaultSetAllocator>);
}
