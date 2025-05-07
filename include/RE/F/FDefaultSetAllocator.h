#pragma once

#include "RE/F/FDefaultBitArrayAllocator.h"
#include "RE/T/TSetAllocator.h"
#include "RE/T/TSizedDefaultAllocator.h"
#include "RE/T/TSizedInlineAllocator.h"
#include "RE/T/TSparseArrayAllocator.h"

namespace RE::UE
{
	class FDefaultSetAllocator :
		public TSetAllocator<TSparseArrayAllocator<TSizedDefaultAllocator<32>, FDefaultBitArrayAllocator>, TSizedInlineAllocator<1, 32, TSizedDefaultAllocator<32>>, 2, 8, 4>
	{
	public:
	};
	static_assert(std::is_empty_v<FDefaultSetAllocator>);
}
