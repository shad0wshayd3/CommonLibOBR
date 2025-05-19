#pragma once

#include "RE/C/CombatStyleData.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class AdvancedCombatStyleData;

	class TESCombatStyle :
		public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESCombatStyle;
		inline static constexpr auto VTABLE = VTABLE::TESCombatStyle;
		inline static constexpr auto FORMTYPE = FormType::CombatStyle;

		// members
		CombatStyleData          data;          // 30
		AdvancedCombatStyleData* advancedData;  // B0
	};
	static_assert(sizeof(TESCombatStyle) == 0xB8);
}
