#pragma once

#include "RE/T/TESModel.h"

namespace RE
{
	class TESModelTree :
		public TESModel
	{
	public:
	};
	static_assert(sizeof(TESModelTree) == 0x30);
}
