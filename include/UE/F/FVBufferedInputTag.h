#pragma once

#include "UE/F/FGameplayTag.h"

namespace UE
{
	class FVBufferedInputTag
	{
	public:
		// members
		FGameplayTag tag;            // 000
		float        remainingTime;  // 008
	};
	static_assert(sizeof(FVBufferedInputTag) == 0xC);
}
