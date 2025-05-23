#pragma once

#include "UE/U/UTESBoundObject.h"

namespace UE
{
	class USkeleton;
	class UTESActorBaseData;

	class UTESActorBase :
		public UTESBoundObject
	{
	public:
		UE_DEFINE_UOBJECT(UTESActorBase, UTESBoundObject, "Altar", "TESActorBase");

		// override
		virtual ~UTESActorBase();  // 00

		// members
		FString                   fullName;                // 190
		UTESActorBaseData*        inheritedActorBaseData;  // 1B8
		TSoftObjectPtr<USkeleton> skeleton;                // 1A8
	};
	static_assert(sizeof(UTESActorBase) == 0x1D0);
}
