#pragma once

namespace RE
{
	struct AIDATA
	{
	public:
		// members
		std::uint8_t  aggression;      // 00
		std::uint8_t  confidence;      // 01
		std::uint8_t  energy;          // 02
		std::uint8_t  responsibility;  // 03
		std::uint32_t serviceFlags;    // 04
		std::uint8_t  trainingSkill;   // 08
		std::uint8_t  trainingLevel;   // 09
	};
	static_assert(sizeof(AIDATA) == 0x0C);
}
