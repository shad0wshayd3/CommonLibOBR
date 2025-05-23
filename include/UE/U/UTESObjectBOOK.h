#pragma once

#include "UE/U/UTESBoundObject.h"

namespace UE
{
	class UStreamableRenderAsset;

	class UTESObjectBOOK :
		public UTESBoundObject
	{
	public:
		UE_DEFINE_UOBJECT(UTESObjectBOOK, UTESBoundObject, "Altar", "TESObjectBOOK");

		// override
		virtual ~UTESObjectBOOK();  // 00

		// members
		FString                                fullName;  // 190
		TSoftObjectPtr<UStreamableRenderAsset> newMesh;   // 1A0
	};
	static_assert(sizeof(UTESObjectBOOK) == 0x1C8);
}
