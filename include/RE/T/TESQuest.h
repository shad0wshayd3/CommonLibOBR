#pragma once

#include "RE/B/BSStringT.h"
#include "RE/B/BSTList.h"
#include "RE/Q/QUEST_DATA.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESScriptableForm.h"

namespace RE
{
	class ScriptLocals;
	class TESQuestStage;
	class TESQuestTarget;

	class TESQuest :
		public TESForm,
		public TESScriptableForm,
		public TESIcon,
		public TESFullName
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESQuest;
		inline static constexpr auto VTABLE = VTABLE::TESQuest;
		inline static constexpr auto FORMTYPE = FormType::Quest;

		// members
		QUEST_DATA                    data;                 // 78
		BSSimpleList<TESQuestStage*>  stages;               // 80
		BSSimpleList<TESQuestTarget*> targets;              // 90
		TESCondition                  objectiveConditions;  // A0
		ScriptLocals*                 scriptLocals;         // B0
		std::uint8_t                  currentStage;         // B8
		BSString                      formEditorID;         // C0
	};
	static_assert(sizeof(TESQuest) == 0xD0);
}
