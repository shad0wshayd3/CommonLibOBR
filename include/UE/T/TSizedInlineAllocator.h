#pragma once

#include "UE/F/FDefaultAllocator.h"
#include "UE/T/TSizedDefaultAllocator.h"
#include "UE/T/TTypeCompatibleBytes.h"

namespace UE
{
	template <std::uint32_t N, std::int32_t I, class A = FDefaultAllocator>
	class TSizedInlineAllocator
	{
	public:
		using SizeType = typename TBitsToSizeType<I>::Type;

		static constexpr bool NeedsElementType{ true };
		static constexpr bool RequireRangeCheck{ true };

		template <class T>
		class ForElementType
		{
		public:
			// members
			TTypeCompatibleBytes<T>                inlineData[N];  // 00
			typename A::template ForElementType<T> secondaryData;  // ??
		};
		// static_assert(sizeof(ForElementType<std::uint32_t>) == 0x28);

		using ForAnyElementType = void;
	};
	static_assert(std::is_empty_v<TSizedInlineAllocator<4, 32>>);
}
