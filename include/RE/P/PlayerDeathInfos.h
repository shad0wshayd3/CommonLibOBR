#pragma once

namespace RE
{
	class PlayerDeathInfos
	{
	public:
		// members
		std::uint8_t  deathReason[4];  // 00
		TESFormID     killerFormID;    // 04
		std::uint32_t killerEntityID;  // 08
		std::uint16_t killerLevel;     // 0C
	};
	static_assert(sizeof(PlayerDeathInfos) == 0x10);
}
