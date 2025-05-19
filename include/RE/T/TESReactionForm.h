#pragma once

#include "RE/B/BSTList.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class GROUP_REACTION;

	struct TESReactionForm :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESReactionForm;
		inline static constexpr auto VTABLE = VTABLE::TESReactionForm;

		// members
		BSSimpleList<GROUP_REACTION*> reactions;      // 08
		std::uint8_t                  groupFormType;  // 18
	};
	static_assert(sizeof(TESReactionForm) == 0x20);
}
