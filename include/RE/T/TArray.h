#pragma once

#include "RE/T/TSizedDefaultAllocator.h"

namespace RE::UE
{
	template <class T, class Allocator = TSizedDefaultAllocator<32>>
	class TArray
	{
	public:
		// members
		std::byte    allocatorInstance[0x08];  // 00
		std::int32_t arrayNum;                 // 08
		std::int32_t arrayMax;                 // 0C
	};
	static_assert(sizeof(TArray<wchar_t>) == 0x10);
}
