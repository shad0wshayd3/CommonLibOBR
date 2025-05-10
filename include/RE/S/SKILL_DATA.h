#pragma once

#include "RE/S/SPECIALIZATION.h"

namespace RE
{
	struct SKILL_DATA
	{
	public:
		// members
		std::byte      index[4];        // 00
		std::byte      attribute[4];    // 04
		SPECIALIZATION specialization;  // 08
		float          actionValue[2];  // 0C
	};
	static_assert(sizeof(SKILL_DATA) == 0x14);
}
