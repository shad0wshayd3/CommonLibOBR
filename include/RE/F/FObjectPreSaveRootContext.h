#pragma once

#include "RE/F/FObjectPreSaveContext.h"

namespace RE::UE
{
	class FObjectPreSaveRootContext :
		public FObjectPreSaveContext
	{
	public:
	};
	static_assert(sizeof(FObjectPreSaveRootContext) == 0x08);
}
