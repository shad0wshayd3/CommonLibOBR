#pragma once

#include "UE/T/TObjectPtr.h"
#include "UE/T/TVector2.h"

namespace UE
{
	class UMaterialInterface;

	class FLegacyMapMenuLocalMapProperties
	{
	public:
		// members
		TObjectPtr<UMaterialInterface> map;                 // 00
		Math::TVector2<double>         mapSize;             // 08
		Math::TVector2<double>         desiredTextureSize;  // 18
	};
	static_assert(sizeof(FLegacyMapMenuLocalMapProperties) == 0x28);
}
