#pragma once

#include "UE/T/TSizedDefaultAllocator.h"
#include "UE/T/TSizedInlineAllocator.h"

namespace UE
{
	class FDefaultBitArrayAllocator :
		public TSizedInlineAllocator<4, 32, TSizedDefaultAllocator<32>>
	{
	public:
	};
	static_assert(std::is_empty_v<FDefaultBitArrayAllocator>);
}
