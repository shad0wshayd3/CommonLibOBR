#pragma once

#include "RE/S/SPECIALIZATION.h"

namespace RE
{
	struct CLASS_DATA
	{
	public:
		// members
		std::byte      primaryAttribute[4];    // 00
		std::byte      secondaryAttribute[4];  // 04
		SPECIALIZATION specialization;         // 08
		std::byte      majorSkills[28];        // 0C
		std::uint8_t   classFlags;             // 28
		std::int32_t   serviceFlags;           // 2C
		std::uint8_t   trainingSkill;          // 30
		std::uint8_t   trainingLevel;          // 31
	};
	static_assert(sizeof(CLASS_DATA) == 0x34);
}
