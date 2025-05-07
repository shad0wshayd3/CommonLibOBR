#pragma once

#include "UE/T/TSizedDefaultAllocator.h"
#include "UE/T/TTypeCompatibleBytes.h"

namespace UE
{
	template <std::size_t N, std::size_t O, class Allocator>
	class TSizedInlineAllocator
	{
	public:
		template <class T>
		class ForElementType
		{
		public:
			// members
			TTypeCompatibleBytes<T> inlineData[N];        // 00
			std::byte               secondaryData[0x08];  // ??
		};
		// static_assert(sizeof(ForElementType<std::uint32_t>) == 0x28);
	};
	static_assert(std::is_empty_v<TSizedInlineAllocator<4, 32, void*>>);
}
