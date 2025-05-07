#pragma once

#include "UE/T/TSizedHeapAllocator.h"

namespace UE
{
	class FMemory;

	template <std::size_t N>
	class TSizedDefaultAllocator :
		public TSizedHeapAllocator<N, FMemory>
	{
	public:
	};
	static_assert(std::is_empty_v<TSizedDefaultAllocator<32>>);
}
