#pragma once

#include "UE/F/FMemory.h"
#include "UE/T/TBitsToSizeType.h"

namespace UE
{
	class FMemory;
	class FScriptContainerElement;

	template <std::int32_t N, class Memory = FMemory>
	class TSizedHeapAllocator
	{
	public:
		static constexpr bool NeedsElementType{ true };
		static constexpr bool RequireRangeCheck{ true };

		using SizeType = TBitsToSizeType<N>::Type;
		using USizeType = std::make_unsigned_t<SizeType>;

		class ForAnyElementType
		{
		public:
			ForAnyElementType() = default;

			~ForAnyElementType()
			{
				if (data)
					Memory::Free(data);
			}

			FScriptContainerElement* GetAllocation() const
			{
				return data;
			}

			SizeType GetInitialCapacity() const
			{
				return 0;
			}

			// members
			FScriptContainerElement* data{ nullptr };  // 00
		};
		static_assert(sizeof(ForAnyElementType) == 0x08);

		template <class T>
		class ForElementType :
			public ForAnyElementType
		{
		public:
			ForElementType() = default;

			T* GetAllocation() const
			{
				return (T*)ForAnyElementType::GetAllocation();
			}
		};
		static_assert(sizeof(ForElementType<void*>) == 0x08);
	};
	static_assert(std::is_empty_v<TSizedHeapAllocator<32, FMemory>>);
}
