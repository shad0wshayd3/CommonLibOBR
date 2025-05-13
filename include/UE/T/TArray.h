#pragma once

#include "UE/T/TChooseClass.h"
#include "UE/T/TSizedDefaultAllocator.h"

namespace UE
{
	template <class T, class A = TSizedDefaultAllocator<32>>
	class TArray
	{
	public:
		using SizeType = A::SizeType;
		using ElementAllocatorType = TChooseClass<
			A::NeedsElementType, typename A::template ForElementType<T>, typename A::ForAnyElementType>::Result;

		TArray() :
			arrayMax(allocatorInstance.GetInitialCapacity())
		{}

		T* GetData()
		{
			return (T*)allocatorInstance.GetAllocation();
		}

		const T* GetData() const
		{
			return (const T*)allocatorInstance.GetAllocation();
		}

		bool IsEmpty() const
		{
			return arrayNum == 0;
		}

		SizeType Num() const
		{
			return arrayNum;
		}

		SizeType Max() const
		{
			return arrayMax;
		}

		T& operator[](SizeType a_index)
		{
			return GetData()[a_index];
		}

		const T& operator[](SizeType a_index) const
		{
			return GetData()[a_index];
		}

		T*       begin() { return GetData(); }
		const T* begin() const { return GetData(); }
		T*       end() { return GetData() + Num(); }
		const T* end() const { return GetData() + Num(); }

		// members
		ElementAllocatorType allocatorInstance;  // 00
		std::int32_t         arrayNum{ 0 };      // 08
		std::int32_t         arrayMax;           // 0C
	};
	static_assert(sizeof(TArray<wchar_t>) == 0x10);
}
