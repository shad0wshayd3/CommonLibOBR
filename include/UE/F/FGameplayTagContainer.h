#pragma once

#include "UE/F/FGameplayTag.h"
#include "UE/T/TArray.h"

namespace UE
{
	class FGameplayTagContainer
	{
	public:
		// members
		TArray<FGameplayTag> gameplayTags;  // 000
		TArray<FGameplayTag> parentTags;    // 010
	};
	static_assert(sizeof(FGameplayTagContainer) == 0x20);
}
