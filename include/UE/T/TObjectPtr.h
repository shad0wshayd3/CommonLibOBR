#pragma once

#include "UE/F/FObjectPtr.h"

namespace UE
{
	class UClass;

	template <class T>
	class TObjectPtr
	{
	public:
		// members
		union
		{
			FObjectPtr objectPtr;
			T*         debugPtr;
		};
	};
	static_assert(sizeof(TObjectPtr<void*>) == 0x08);
}
