#pragma once

#include "RE/B/BSTList.h"

namespace RE
{
	class FastModifierCollection;
	class Modifier;

	class ModifierList :
		public BSSimpleList<Modifier*>
	{
	public:
		// members
		Modifier*               magickaModifier;  // 10
		Modifier*               fatigueModifier;  // 18
		FastModifierCollection* fastModifiers;    // 20
	};
	static_assert(sizeof(ModifierList) == 0x28);
}
