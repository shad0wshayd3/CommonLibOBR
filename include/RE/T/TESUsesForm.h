#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESUsesForm :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESUsesForm;
		inline static constexpr auto VTABLE = VTABLE::TESUsesForm;

		// members
		std::uint8_t uses;  // 08
	};
	static_assert(sizeof(TESUsesForm) == 0x10);
}
