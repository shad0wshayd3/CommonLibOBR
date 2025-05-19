#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	struct TESAttributes :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESAttributes;
		inline static constexpr auto VTABLE = VTABLE::TESAttributes;

		// members
		std::uint8_t attribute[8];  // 00
	};
	static_assert(sizeof(TESAttributes) == 0x10);
}
