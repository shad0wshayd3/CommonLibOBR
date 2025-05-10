#pragma once

#include "RE/B/BSStringT.h"
#include "RE/B/BSTList.h"
#include "RE/D/DIALOGUE_DATA.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	struct QUEST_INFO;

	class TESTopic :
		public TESForm,
		public TESFullName
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESTopic;
		inline static constexpr auto VTABLE = VTABLE::TESTopic;
		inline static constexpr auto FORMTYPE = FormType::Dialogue;

		// members
		DIALOGUE_DATA             data;          // 48
		BSSimpleList<QUEST_INFO*> questInfo;     // 50
		std::int32_t              journalIndex;  // 60
		BSString                  formEditorID;  // 68
	};
	static_assert(sizeof(TESTopic) == 0x78);
}
