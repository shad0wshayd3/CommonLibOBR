#pragma once

#include "UE/E/ELegacyMapMenuIcon.h"
#include "UE/F/FName.h"
#include "UE/F/FString.h"
#include "UE/F/FText.h"
#include "UE/F/FVector2.h"

namespace UE
{
	class FLegacyMapMenuIconProperties
	{
	public:
		// members
		FVector2d          position;              // 00
		FName              key;                   // 10
		FText              name;                  // 18
		ELegacyMapMenuIcon type;                  // 30
		bool               fastTravelEnabled;     // 31
		std::int32_t       depthAdjustment;       // 34
		bool               isTargetable;          // 38
		bool               isThroughLoadingDoor;  // 39
		float              playerRotation;        // 3C
		FString            iconAddress;           // 40
	};
	static_assert(sizeof(FLegacyMapMenuIconProperties) == 0x50);
}
