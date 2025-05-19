#pragma once

#include "RE/S/SCRIPT_PARAM_TYPE.h"

namespace RE
{
	struct SCRIPT_PARAMETER_DEF
	{
	public:
		// member
		SCRIPT_PARAM_TYPE paramType;         // 00
		bool              canBeVariable;     // 04
		bool              referencedObject;  // 05
	};
	static_assert(sizeof(SCRIPT_PARAMETER_DEF) == 0x08);
}
