#pragma once

namespace RE
{
	class OBJ_WEAP
	{
	public:
		// members
		std::uint8_t type;   // 00
		float        speed;  // 04
		float        reach;  // 08
		std::uint8_t flags;  // 0C
	};
	static_assert(sizeof(OBJ_WEAP) == 0x10);
}
