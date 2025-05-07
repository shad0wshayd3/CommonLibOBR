#pragma once

#include "RE/B/BSStringT.h"
#include "RE/B/BSTList.h"
#include "RE/C/CompilerName.h"
#include "RE/S/ScriptError.h"
#include "RE/S/ScriptHeader.h"

namespace RE
{
	class Script;
	class ScriptVariable;

	struct SCRIPT_LINE;
	struct SCRIPT_REFERENCED_OBJECT;

	class ScriptCompileData
	{
	public:
		// members
		const char*                             input;            // 00
		std::uint32_t                           inputOffset;      // 08
		COMPILER_NAME                           compilerIndex;    // 0C
		BSString                                scriptName;       // 10
		SCRIPT_ERROR                            lastError;        // 20
		bool                                    isPartialScript;  // 24
		std::uint32_t                           lastLineNumber;   // 28
		char*                                   output;           // 30
		std::uint32_t                           outputOffset;     // 38
		SCRIPT_HEADER                           header;           // 3C
		BSSimpleList<ScriptVariable*>           listVariables;    // 50
		BSSimpleList<SCRIPT_REFERENCED_OBJECT*> listRefObjects;   // 60
		Script*                                 currentScript;    // 70
		BSSimpleList<SCRIPT_LINE*>              listLines;        // 78
	};
	static_assert(sizeof(ScriptCompileData) == 0x88);
}
