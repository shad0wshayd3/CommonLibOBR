#pragma once

#include "UE/F/FObjectPostSaveContext.h"

namespace UE
{
	class FObjectPostSaveRootContext :
		public FObjectPostSaveContext
	{
	public:
	};
	static_assert(sizeof(FObjectPostSaveRootContext) == 0x08);
}
