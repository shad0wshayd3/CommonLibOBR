#pragma once

#include "RE/T/TESCondition.h"

namespace RE
{
	class TESObjectREFR;

	class TESQuestTarget
	{
	public:
		// members
		std::uint8_t   flags;            // 00
		TESCondition   objConditions;    // 08
		TESObjectREFR* targetRef;        // 18
		TESObjectREFR* closestLoadDoor;  // 20
	};
	static_assert(sizeof(TESQuestTarget) == 0x28);
}
