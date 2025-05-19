#pragma once

#include "RE/T/TESObjectMISC.h"

namespace RE
{
	class TESSoulGem :
		public TESObjectMISC
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESSoulGem;
		inline static constexpr auto VTABLE = VTABLE::TESSoulGem;
		inline static constexpr auto FORMTYPE = FormType::SoulGem;

		// members
		std::uint8_t currentSoul;   // E0
		std::uint8_t soulCapacity;  // E1
	};
	static_assert(sizeof(TESSoulGem) == 0xE8);
}
