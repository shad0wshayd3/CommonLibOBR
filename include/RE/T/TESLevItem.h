#pragma once

#include "RE/T/TESBoundObject.h"
#include "RE/T/TESLeveledList.h"

namespace RE
{
	class TESLevItem :
		public TESBoundObject,
		public TESLeveledList
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESLevItem;
		inline static constexpr auto VTABLE = VTABLE::TESLevItem;
		inline static constexpr auto FORMTYPE = FormType::LeveledItem;
	};
	static_assert(sizeof(TESLevItem) == 0x68);
}
