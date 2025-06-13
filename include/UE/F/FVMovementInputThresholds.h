#pragma once

#include "UE/F/FGameplayTag.h"
#include "UE/T/TMap.h"

namespace UE
{
	class FVMovementInputThresholds
	{
	public:
		// members
		TMap<float, FGameplayTag> maxGaitForThresholds;  // 00
	};
	static_assert(sizeof(FVMovementInputThresholds) == 0x50);
}
