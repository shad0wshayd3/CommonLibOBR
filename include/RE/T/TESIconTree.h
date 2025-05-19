#pragma once

#include "RE/T/TESTexture.h"

namespace RE
{
	class TESIconTree :
		public TESTexture
	{
	public:
	};
	static_assert(sizeof(TESIconTree) == 0x18);
}
