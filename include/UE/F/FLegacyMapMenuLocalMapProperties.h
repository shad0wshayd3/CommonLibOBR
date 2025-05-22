#pragma once

#include "UE/F/FVector2.h"
#include "UE/T/TObjectPtr.h"

namespace UE
{
	class UMaterialInterface;

	class FLegacyMapMenuLocalMapProperties
	{
	public:
		// members
		TObjectPtr<UMaterialInterface> map;                 // 00
		FVector2d                      mapSize;             // 08
		FVector2d                      desiredTextureSize;  // 18
	};
	static_assert(sizeof(FLegacyMapMenuLocalMapProperties) == 0x28);
}
