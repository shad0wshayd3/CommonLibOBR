#pragma once

#include "UE/F/FSoftObjectPtr.h"

namespace UE
{
	template <class T = UObject>
	class TSoftObjectPtr
	{
	public:
		// members
		FSoftObjectPtr softObjectPtr;
	};
	static_assert(sizeof(TSoftObjectPtr<UObject>) == 0x28);
}
