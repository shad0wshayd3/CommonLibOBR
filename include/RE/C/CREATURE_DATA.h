#pragma once

namespace RE
{
	class CREATURE_DATA
	{
	public:
		// members
		std::uint8_t  type;     // 00
		std::uint8_t  combat;   // 01
		std::uint8_t  magic;    // 02
		std::uint8_t  stealth;  // 03
		std::uint16_t soul;     // 04
	};
	static_assert(sizeof(CREATURE_DATA) == 0x06);
}
