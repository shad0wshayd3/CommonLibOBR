#pragma once

#include "RE/M/MagicSystem.h"

namespace RE
{
	class SpellItemData
	{
	public:
		// members
		MagicSystem::SpellType spellType;         // 00
		std::int32_t           costOverride;      // 04
		std::byte              levelOverride[4];  // 08
		std::uint8_t           flags;             // 0C
	};
	static_assert(sizeof(SpellItemData) == 0x10);
}
