#pragma once

#include "UE/U/UTESForm.h"

namespace UE
{
	class UTESFaction :
		public UTESForm
	{
	public:
		UE_DEFINE_UOBJECT("Altar", "TESFaction");

		// override
		virtual ~UTESFaction();  // 00
	};
	static_assert(sizeof(UTESFaction) == 0x0D8);
}
