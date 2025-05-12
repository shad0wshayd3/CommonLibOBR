#pragma once

#include "UE/F/FDefaultAllocator.h"
#include "UE/T/TArray.h"

namespace UE
{
	template <class T, class Allocator = FDefaultAllocator>
	class TIndirectArray
	{
	public:
		// members
		TArray<void*, Allocator> array;
	};
}
