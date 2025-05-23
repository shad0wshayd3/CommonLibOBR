#pragma once

#include "UE/U/UTESBoundObject.h"

namespace UE
{
	class UTESLeveledList;

	class UTESLevCreature :
		public UTESBoundObject
	{
	public:
		UE_DEFINE_UOBJECT(UTESLevCreature, UTESBoundObject, "Altar", "TESLevCreature");

		// override
		virtual ~UTESLevCreature();  // 00

		// members
		UTESLeveledList* inheritedLeveledList;  // 190
	};
	static_assert(sizeof(UTESLevCreature) == 0x198);
}
