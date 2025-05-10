#pragma once

#include "RE/S/SKILL_DATA.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class TESSkill :
		public TESForm,
		public TESDescription,
		public TESTexture
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESSkill;
		inline static constexpr auto VTABLE = VTABLE::TESSkill;
		inline static constexpr auto FORMTYPE = FormType::Skill;

		// members
		SKILL_DATA     data;               // 58
		TESDescription skillLevelText[4];  // 70
	};
	static_assert(sizeof(TESSkill) == 0xB0);
}
