#pragma once

#include "RE/T/TESBoundObject.h"
#include "RE/T/TESLeveledList.h"

namespace RE
{
	class TESLevSpell :
		public TESBoundObject,
		public TESLeveledList
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESLevSpell;
		inline static constexpr auto VTABLE = VTABLE::TESLevSpell;
		inline static constexpr auto FORMTYPE = FormType::LeveledSpell;
	};
	static_assert(sizeof(TESLevSpell) == 0x68);
}
