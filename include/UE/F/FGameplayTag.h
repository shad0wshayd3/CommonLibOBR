#pragma once

#include "UE/F/FName.h"

namespace UE
{
	class FGameplayTag
	{
	public:
		// members
		FName tagName;  // 000
	};
	static_assert(sizeof(FGameplayTag) == 0x8);
}
