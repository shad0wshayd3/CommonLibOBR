#pragma once

#include "UE/F/FText.h"
#include "UE/T/TObjectPtr.h"

namespace UE
{
	class UTexture2D;

	class FLegacyMapMenuQuestProperties
	{
	public:
		// members
		FText                  name;              // 00
		FText                  date;              // 18
		FText                  body;              // 30
		FText                  controllerText;    // 48
		FText                  keyboardText;      // 60
		TObjectPtr<UTexture2D> icon;              // 78
		bool                   isActive;          // 80
		std::int32_t           questId;           // 84
		std::int32_t           questPriority;     // 88
		bool                   isQuestCompleted;  // 8C
		std::int32_t           questIndex;        // 90
	};
	static_assert(sizeof(FLegacyMapMenuQuestProperties) == 0x98);
}
