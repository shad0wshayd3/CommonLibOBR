#pragma once

#include "UE/U/UTESBoundObject.h"

namespace UE
{
	class UStreamableRenderAsset;

	class UTESObjectAPPA :
		public UTESBoundObject
	{
	public:
		UE_DEFINE_UOBJECT(UTESObjectAPPA, UTESBoundObject, "Altar", "TESObjectAPPA");

		// override
		virtual ~UTESObjectAPPA();  // 00

		// members
		FString                                fullName;  // 190
		TSoftObjectPtr<UStreamableRenderAsset> newMesh;   // 1A0
	};
	static_assert(sizeof(UTESObjectAPPA) == 0x1C8);
}
