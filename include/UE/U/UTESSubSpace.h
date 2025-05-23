#pragma once

#include "UE/U/UTESBoundObject.h"

namespace UE
{
	class UTESSubSpace :
		public UTESBoundObject
	{
	public:
		UE_DEFINE_UOBJECT(UTESSubSpace, UTESBoundObject, "Altar", "TESSubSpace");

		// override
		virtual ~UTESSubSpace();  // 00

		// members
		FVector dimensions;  // 190
	};
	static_assert(sizeof(UTESSubSpace) == 0x1A8);
}
