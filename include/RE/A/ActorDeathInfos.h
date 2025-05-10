#pragma once

#include "RE/F/FormTypes.h"

namespace RE
{
	class ActorDeathInfos
	{
	public:
		// members
		FormType                          lastHitFormType;       // 00
		TESFormID                         lastHitFormID;         // 04
		float                             lastHitDamageAmount;   // 08
		float                             lastHitDamagePercent;  // 0C
		std::unordered_set<std::uint32_t> otherDamageSources;    // 10
		std::int32_t                      combatStartTime;       // 50
	};
	static_assert(sizeof(ActorDeathInfos) == 0x58);
}
