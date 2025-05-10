#pragma once

#include "RE/M/MagicItemForm.h"
#include "RE/S/SpellItemData.h"

namespace RE
{
	class SpellItem :
		public MagicItemForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::SpellItem;
		inline static constexpr auto VTABLE = VTABLE::SpellItem;
		inline static constexpr auto FORMTYPE = FormType::Spell;

		// members
		SpellItemData data;  // 90
	};
	static_assert(sizeof(SpellItem) == 0xA0);
}
