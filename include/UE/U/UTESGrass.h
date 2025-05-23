#pragma once

#include "UE/F/FTESGrassData.h"
#include "UE/U/UTESBoundObject.h"

namespace UE
{
	class UStreamableRenderAsset;

	class UTESGrass :
		public UTESBoundObject
	{
	public:
		UE_DEFINE_UOBJECT(UTESGrass, UTESBoundObject, "Altar", "TESGrass");

		// override
		virtual ~UTESGrass();  // 00

		// members
		FTESGrassData data;  // 190
	};
	static_assert(sizeof(UTESGrass) == 0x1B0);
}
