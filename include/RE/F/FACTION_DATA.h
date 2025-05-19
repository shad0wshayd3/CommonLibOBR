#pragma once

namespace RE
{
	struct FACTION_DATA
	{
	public:
		// members
		std::uint8_t flags;  // 00
	};
	static_assert(sizeof(FACTION_DATA) == 0x01);
}
