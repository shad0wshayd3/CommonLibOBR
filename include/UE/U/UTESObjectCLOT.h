#pragma once

#include "UE/U/UTESBoundObject.h"

namespace UE
{
	class UTESObjectCLOT :
		public UTESBoundObject
	{
	public:
		UE_DEFINE_UOBJECT(UTESObjectCLOT, UTESBoundObject, "Altar", "TESObjectCLOT");

		// override
		virtual ~UTESObjectCLOT();  // 00

		// members
		FString             fullName;             // 190
		UTESBipedModelForm* inheritedBipedModel;  // 1A0
	};
	static_assert(sizeof(UTESObjectCLOT) == 0x1A8);
}
