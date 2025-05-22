#pragma once

#include "RE/F/FormTypes.h"

namespace RE
{
	class alignas(8) ActorDeathInfos
	{
	public:
		// members
		FormType     lastHitFormType;           // 00
		TESFormID    lastHitFormID;             // 04
		float        lastHitDamageAmount;       // 08
		float        lastHitDamagePercent;      // 0C
		std::byte    otherDamageSources[0x40];  // 10 - std::unordered_set<std::uint32_t> [BAD!]
		std::int32_t combatStartTime;           // 50
	};
	static_assert(sizeof(ActorDeathInfos) == 0x58);
}
