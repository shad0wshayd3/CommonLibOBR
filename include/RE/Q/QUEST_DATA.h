#pragma once

namespace RE
{
	struct QUEST_DATA
	{
	public:
		// members
		std::uint8_t flags;     // 00
		std::uint8_t priority;  // 01
	};
	static_assert(sizeof(QUEST_DATA) == 0x02);
}
