#pragma once

#include "UE/U/UTESBoundObject.h"

namespace UE
{
	class UTESObjectARMO :
		public UTESBoundObject
	{
	public:
		UE_DEFINE_UOBJECT(UTESObjectARMO, UTESBoundObject, "Altar", "TESObjectARMO");

		// override
		virtual ~UTESObjectARMO();  // 00

		// members
		FString             fullName;             // 190
		UTESBipedModelForm* inheritedBipedModel;  // 1A0
		bool                isShield;             // 1A8
	};
	static_assert(sizeof(UTESObjectARMO) == 0x1B0);
}
