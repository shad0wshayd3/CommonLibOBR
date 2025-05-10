#pragma once

#include "RE/B/BSTList.h"
#include "RE/S/SCRIPT_HEADER.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class ScriptVariable;

	struct SCRIPT_REFERENCED_OBJECT;

	class Script :
		public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::Script;
		inline static constexpr auto VTABLE = VTABLE::Script;
		inline static constexpr auto FORMTYPE = FormType::Script;

		// override (TESForm)
		virtual ~Script() override;                       // 04
		virtual void InitializeData() override;           // 05
		virtual void ClearData() override;                // 06
		virtual bool Load(TESFile* a_file) override;      // 07
		virtual void Save() override;                     // 09
		virtual bool SaveEdit(TESFile* a_file) override;  // 0B
		virtual void InitItem() override;                 // 1B

		// members
		SCRIPT_HEADER                           header;                       // 30
		char*                                   text;                         // 48
		char*                                   data;                         // 50
		float                                   profilerTimer;                // 58
		float                                   questScriptDelay;             // 5C
		float                                   questScriptGetSecondsBuffer;  // 60
		BSSimpleList<SCRIPT_REFERENCED_OBJECT*> listRefObjects;               // 68
		BSSimpleList<ScriptVariable*>           listVariables;                // 78
	};
	static_assert(sizeof(Script) == 0x88);
}
