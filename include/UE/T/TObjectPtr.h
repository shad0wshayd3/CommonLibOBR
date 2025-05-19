#pragma once

#include "UE/F/FObjectPtr.h"

namespace UE
{
	class UClass;

	template <class T>
	class TObjectPtr
	{
	public:
		T* Get() const
		{
			return static_cast<T*>(objectPtr.Get());
		}

		explicit operator bool() const
		{
			return objectPtr.operator bool();
		}

		operator T*() const
		{
			return Get();
		}

		T* operator->() const
		{
			return Get();
		}

		T& operator*() const
		{
			return *Get();
		}

		// members
		union
		{
			FObjectPtr objectPtr;
			T*         debugPtr;
		};
	};
	static_assert(sizeof(TObjectPtr<void*>) == 0x08);
}
