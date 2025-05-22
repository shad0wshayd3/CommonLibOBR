#pragma once

#include "UE/F/FLegacyMapMenuLocalMapProperties.h"
#include "UE/F/FLegacyMapMenuWorldMapProperties.h"
#include "UE/F/FVector2.h"
#include "UE/T/TArray.h"
#include "UE/U/UVViewModelBase.h"

namespace UE
{
	class FLegacyMapMenuIconProperties;

	class UVMapPageViewModel :
		public UVViewModelBase
	{
	public:
		UE_DEFINE_UOBJECT(UVMapPageViewModel, UVViewModelBase, "Altar", "VMapPageViewModel");

		// members
		TArray<float>                        fogDatas;                               // 0D0
		FLegacyMapMenuWorldMapProperties     worldMapProperties;                     // 0E0
		FLegacyMapMenuLocalMapProperties     localMapProperties;                     // 100
		TArray<FLegacyMapMenuIconProperties> mapIcons;                               // 128
		FVector2d                            mapPosition;                            // 138
		FVector2d                            playerMarkerPosition;                   // 148
		float                                zoom;                                   // 158
		float                                minZoomValue;                           // 15C
		float                                maxZoomValue;                           // 160
		bool                                 hasTriedFastTravel;                     // 164
		bool                                 lockingUpdatesDuringDelayedFastTravel;  // 165
	};
	static_assert(sizeof(UVMapPageViewModel) == 0x168);
}
