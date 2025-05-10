#pragma once

#include "RE/B/BSTList.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class SpellItem;
	class TESLevSpell;

	struct TESSpellList :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESSpellList;
		inline static constexpr auto VTABLE = VTABLE::TESSpellList;

		// members
		BSSimpleList<SpellItem*>   spells;     // 08
		BSSimpleList<TESLevSpell*> levSpells;  // 18
	};
	static_assert(sizeof(TESSpellList) == 0x28);
}
