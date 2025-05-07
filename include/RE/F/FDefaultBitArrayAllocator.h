#pragma once

#include "RE/T/TSizedDefaultAllocator.h"
#include "RE/T/TSizedInlineAllocator.h"

namespace RE::UE
{
	class FDefaultBitArrayAllocator :
		public TSizedInlineAllocator<4, 32, TSizedDefaultAllocator<32>>
	{
	public:
	};
	static_assert(std::is_empty_v<FDefaultBitArrayAllocator>);
}
