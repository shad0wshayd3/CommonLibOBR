#pragma once

#include "UE/T/TInlineAllocator.h"
#include "UE/T/TSparseArrayAllocator.h"

namespace UE
{
	template <class A1 = TSparseArrayAllocator<>, class A2 = TInlineAllocator<1>, std::uint32_t NA = 2, std::uint32_t NB = 8, std::uint32_t NM = 4>
	class TSetAllocator
	{
	public:
		using SparseArrayAllocator = A1;
		using HashAllocator = A2;
	};
	static_assert(std::is_empty_v<TSetAllocator<>>);
}
