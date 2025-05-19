#pragma once

#include "UE/F/FSoftObjectPtr.h"

namespace UE
{
	template <class T = UObject>
	class TSoftClassPtr
	{
	public:
		// members
		FSoftObjectPtr softObjectPtr;
	};
	static_assert(sizeof(TSoftClassPtr<UObject>) == 0x28);
}
