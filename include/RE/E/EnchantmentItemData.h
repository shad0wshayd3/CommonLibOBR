#pragma once

#include "RE/M/MagicSystem.h"

namespace RE
{
	class EnchantmentItemData
	{
	public:
		// members
		MagicSystem::CastingType castingType;     // 00
		std::int32_t             chargeOverride;  // 04
		std::int32_t             costOverride;    // 08
		std::uint8_t             flags;           // 0C
	};
	static_assert(sizeof(EnchantmentItemData) == 0x10);
}
