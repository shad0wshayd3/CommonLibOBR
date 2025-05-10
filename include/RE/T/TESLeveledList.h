#pragma once

#include "RE/B/BSTList.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class LEVELED_OBJECT;

	struct TESLeveledList :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESLeveledList;
		inline static constexpr auto VTABLE = VTABLE::TESLeveledList;

		// members
		BSSimpleList<LEVELED_OBJECT*> leveledList;       // 08
		std::uint8_t                  chanceNone;        // 18
		std::uint8_t                  leveledListFlags;  // 19
	};
	static_assert(sizeof(TESLeveledList) == 0x20);
}
