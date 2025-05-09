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
