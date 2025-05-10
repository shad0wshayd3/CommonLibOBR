#pragma once

#include "RE/S/SKILL_BONUS.h"

namespace RE
{
	struct RACE_DATA
	{
	public:
		// members
		SKILL_BONUS  skillBonus[7];  // 00
		float        height[2];      // 10
		float        weight[2];      // 18
		std::int32_t flags;          // 20
	};
	static_assert(sizeof(RACE_DATA) == 0x24);
}
