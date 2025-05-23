#pragma once

#include "UE/U/UTESBoundObject.h"

namespace UE
{
	class UStreamableRenderAsset;
	class UTexture2D;

	class UTESObjectMISC :
		public UTESBoundObject
	{
	public:
		UE_DEFINE_UOBJECT(UTESObjectMISC, UTESBoundObject, "Altar", "TESObjectMISC");

		// override
		virtual ~UTESObjectMISC();  // 00

		// members
		FString                                fullName;     // 190
		TSoftObjectPtr<UTexture2D>             textureIcon;  // 1A0
		TSoftObjectPtr<UStreamableRenderAsset> newMesh;      // 1C8
	};
	static_assert(sizeof(UTESObjectMISC) == 0x1F0);
}
