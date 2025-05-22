#pragma once

#include "UE/T/TObjectPtr.h"
#include "UE/T/TVector2.h"

namespace UE
{
	class UObject;

	class FLegacyMapMenuWorldMapProperties
	{
	public:
		// members
		TObjectPtr<UObject>    map;          // 00
		Math::TVector2<double> mapSize;      // 08
		bool                   isMainWorld;  // 18
	};
	static_assert(sizeof(FLegacyMapMenuWorldMapProperties) == 0x20);
}
