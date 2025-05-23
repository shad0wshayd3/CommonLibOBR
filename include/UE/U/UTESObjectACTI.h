#pragma once

#include "UE/U/UTESBoundObject.h"

namespace UE
{
	class UTESObjectACTI :
		public UTESBoundObject
	{
	public:
		UE_DEFINE_UOBJECT(UTESObjectACTI, UTESBoundObject, "Altar", "TESObjectACTI");

		// override
		virtual ~UTESObjectACTI();  // 00

		// members
		FString                        fullName;  // 190
		TSoftObjectPtr<UAnimBlueprint> newMesh;   // 1A0
	};
	static_assert(sizeof(UTESObjectACTI) == 0x1C8);
}
