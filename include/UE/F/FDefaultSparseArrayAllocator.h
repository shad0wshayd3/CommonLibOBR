#pragma once

#include "UE/F/FDefaultBitArrayAllocator.h"
#include "UE/T/TSizedDefaultAllocator.h"
#include "UE/T/TSparseArrayAllocator.h"

namespace UE
{
	class FDefaultSparseArrayAllocator :
		public TSparseArrayAllocator<>
	{
	public:
	};
	static_assert(std::is_empty_v<FDefaultSparseArrayAllocator>);
}
