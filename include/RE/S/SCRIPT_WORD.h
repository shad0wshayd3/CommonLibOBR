#pragma once

#include "RE/S/SCRIPT_OUTPUT.h"

namespace RE
{
	class TESForm;

	struct SCRIPT_WORD
	{
	public:
		// members
		char          text[512];       // 000
		std::uint32_t refObjectIndex;  // 200
		std::uint8_t  variableType;    // 204
		SCRIPT_OUTPUT functionCode;    // 208
		std::uint32_t variableID;      // 20C
		TESForm*      form;            // 210
	};
	static_assert(sizeof(SCRIPT_WORD) == 0x218);
}
