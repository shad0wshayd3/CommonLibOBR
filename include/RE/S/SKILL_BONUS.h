#pragma once

namespace RE
{
	struct SKILL_BONUS
	{
	public:
		// members
		std::uint8_t skill;  // 00
		std::uint8_t bonus;  // 01
	};
	static_assert(sizeof(SKILL_BONUS) == 0x02);
}
