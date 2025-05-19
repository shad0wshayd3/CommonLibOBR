#pragma once

#include "UE/F/FObjectPreSaveContext.h"

namespace UE
{
	class FObjectPreSaveRootContext :
		public FObjectPreSaveContext
	{
	public:
	};
	static_assert(sizeof(FObjectPreSaveRootContext) == 0x08);
}
