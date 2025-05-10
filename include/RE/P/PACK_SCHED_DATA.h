#pragma once

namespace RE
{
	struct PACK_SCHED_DATA
	{
	public:
		// members
		std::uint8_t month;      // 00
		std::uint8_t dayOfWeek;  // 01
		std::uint8_t date;       // 02
		std::uint8_t time;       // 03
		std::int32_t duration;   // 04
	};
	static_assert(sizeof(PACK_SCHED_DATA) == 0x08);
}
