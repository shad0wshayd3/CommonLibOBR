#pragma once

#include "UE/U/UTESBoundObject.h"

namespace UE
{
	class UStreamableRenderAsset;

	class UTESObjectSTAT :
		public UTESBoundObject
	{
	public:
		UE_DEFINE_UOBJECT(UTESObjectSTAT, UTESBoundObject, "Altar", "TESObjectSTAT");

		// override
		virtual ~UTESObjectSTAT();  // 00

		// members
		TSoftObjectPtr<UAnimBlueprint>         posePairingAnimBlueprint;  // 190
		TSoftObjectPtr<UStreamableRenderAsset> newMesh;                   // 1B8
	};
	static_assert(sizeof(UTESObjectSTAT) == 0x1E0);
}
