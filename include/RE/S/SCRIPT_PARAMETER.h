#pragma once

#include "RE/S/SCRIPT_PARAM_TYPE.h"

namespace RE
{
	struct SCRIPT_PARAMETER
	{
	public:
		// members
		char*             paramName;  //00
		SCRIPT_PARAM_TYPE paramType;  //08
		bool              optional;   //0C
	};
	static_assert(sizeof(SCRIPT_PARAMETER) == 0x10);
}
