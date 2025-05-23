#pragma once

#include "UE/E/EOblivionWeaponType.h"
#include "UE/U/UTESBoundObject.h"

namespace UE
{
	class UStreamableRenderAsset;
	class UTexture2D;
	class UTESIcon;

	class UTESObjectWEAP :
		public UTESBoundObject
	{
	public:
		UE_DEFINE_UOBJECT(UTESObjectWEAP, UTESBoundObject, "Altar", "TESObjectWEAP");

		// override
		virtual ~UTESObjectWEAP();  // 00

		// members
		FString                                fullName;           // 190
		TSoftObjectPtr<UTexture2D>             textureIcon;        // 1B8
		EOblivionWeaponType                    type;               // 1C8
		float                                  speed;              // 1CC
		TSoftObjectPtr<UStreamableRenderAsset> newMesh;            // 1D0
		TSoftObjectPtr<UStreamableRenderAsset> newScabbardMesh;    // 1F8
		TSoftObjectPtr<UStreamableRenderAsset> newWeaponOnlyMesh;  // 220
		UTESIcon*                              inheritedIcon;      // 248
	};
	static_assert(sizeof(UTESObjectWEAP) == 0x250);
}
