#pragma once

#include "UE/U/UCheatManager.h"

namespace UE
{
	class UAltarCheatManager :
		public UCheatManager
	{
	public:
		UE_DEFINE_OBJECT("/Script/Altar", "AltarCheatManager");

		// override
		virtual ~UAltarCheatManager();  // 00
	};
}
