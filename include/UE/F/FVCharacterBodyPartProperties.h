#pragma once

#include "UE/T/TSharedPtr.h"
#include "UE/T/TSubclassOf.h"

namespace UE
{
	class AVModularBodyPartBase;
	class FStreamableHandle;
	class UTESForm;

	class FVCharacterBodyPartProperties
	{
	public:
		// members
		bool                               isCovered;           // 000
		const UTESForm*                    equipmentForm;       // 008
		TSubclassOf<AVModularBodyPartBase> equippedClass;       // 010
		TSharedPtr<FStreamableHandle>      asyncLoadingHandle;  // 018
	};
	static_assert(sizeof(FVCharacterBodyPartProperties) == 0x28);
}
