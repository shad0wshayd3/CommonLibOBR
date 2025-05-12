#pragma once

#include "UE/U/UObject.h"

namespace UE
{
	class UTESBaseFormComponent :
		public UObject
	{
	public:
		UE_DEFINE_OBJECT("/Script/Altar", "TESBaseFormComponent");

		// override
		virtual ~UTESBaseFormComponent();

		// add
		virtual void Read();  // 57
	};
	static_assert(sizeof(UTESBaseFormComponent) == 0x28);
}
