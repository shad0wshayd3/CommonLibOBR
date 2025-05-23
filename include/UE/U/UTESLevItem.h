#pragma once

#include "UE/U/UTESBoundObject.h"

namespace UE
{
	class UTESLevItem :
		public UTESBoundObject
	{
	public:
		UE_DEFINE_UOBJECT(UTESLevItem, UTESBoundObject, "Altar", "TESLevItem");

		// override
		virtual ~UTESLevItem();  // 00
	};
	static_assert(sizeof(UTESLevItem) == 0x190);
}
