#pragma once

#include "UE/F/FVector2.h"
#include "UE/T/TObjectPtr.h"

namespace UE
{
	class UObject;

	class FLegacyMapMenuWorldMapProperties
	{
	public:
		// members
		TObjectPtr<UObject> map;          // 00
		FVector2d           mapSize;      // 08
		bool                isMainWorld;  // 18
	};
	static_assert(sizeof(FLegacyMapMenuWorldMapProperties) == 0x20);
}
