#pragma once

#include "UE/T/TSizedHeapAllocator.h"

namespace UE
{
	class FMemory;

	template <std::int32_t N>
	class TSizedDefaultAllocator :
		public TSizedHeapAllocator<N>
	{
	public:
	};
	static_assert(std::is_empty_v<TSizedDefaultAllocator<32>>);
}
