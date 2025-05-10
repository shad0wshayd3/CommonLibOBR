#pragma once

#include "RE/N/NiPoint3.h"

namespace RE
{
	class TESBoundObject;

	struct OBJ_REFR
	{
	public:
		// members
		TESBoundObject* objectReference;  // 00
		NiPoint3        angle;            // 08
		NiPoint3        location;         // 14
	};
	static_assert(sizeof(OBJ_REFR) == 0x20);
}
