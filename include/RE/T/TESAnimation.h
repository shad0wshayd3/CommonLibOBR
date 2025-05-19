#pragma once

#include "RE/B/BSTList.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class SpellItem;
	class TESLevSpell;

	struct TESAnimation :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESAnimation;
		inline static constexpr auto VTABLE = VTABLE::TESAnimation;

		// members
		BSSimpleList<const char*> kfFileNames;  // 08
	};
	static_assert(sizeof(TESAnimation) == 0x18);
}
