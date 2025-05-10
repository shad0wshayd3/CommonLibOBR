#pragma once

namespace RE
{
	struct AMMO_DATA
	{
	public:
		// members
		float        speed;  // 00
		std::uint8_t flags;  // 04
	};
	static_assert(sizeof(AMMO_DATA) == 0x08);
}
