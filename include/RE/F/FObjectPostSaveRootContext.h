#pragma once

#include "RE/F/FObjectPostSaveContext.h"

namespace RE::UE
{
	class FObjectPostSaveRootContext :
		public FObjectPostSaveContext
	{
	public:
	};
	static_assert(sizeof(FObjectPostSaveRootContext) == 0x08);
}
