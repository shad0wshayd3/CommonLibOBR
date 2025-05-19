#pragma once

#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESLeveledList.h"
#include "RE/T/TESScriptableForm.h"

namespace RE
{
	class TESActorBase;

	class TESLevCreature :
		public TESBoundAnimObject,
		public TESLeveledList,
		public TESScriptableForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESLevCreature;
		inline static constexpr auto VTABLE = VTABLE::TESLevCreature;
		inline static constexpr auto FORMTYPE = FormType::LeveledCreature;

		// members
		TESActorBase* _template;  // 80
	};
	static_assert(sizeof(TESLevCreature) == 0x88);
}
