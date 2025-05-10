#pragma once

namespace RE
{
	struct ACTOR_BASE_DATA
	{
	public:
		// members
		std::int32_t  actorBaseFlags;  // 00
		std::uint16_t spellPoints;     // 04
		std::uint16_t fatigue;         // 06
		std::uint16_t barterGold;      // 08
		std::int16_t  level;           // 0A
		std::uint16_t calcLevelMin;    // 0C
		std::uint16_t calcLevelMax;    // 0E
	};
	static_assert(sizeof(ACTOR_BASE_DATA) == 0x10);
}
