#pragma once

#include "UE/F/FStructuredArchiveSlotBase.h"

namespace UE
{
	class FStructuredArchiveSlot :
		public StructuredArchive::Private::FSlotBase
	{
	public:
	};
	static_assert(sizeof(FStructuredArchiveSlot) == 0x08);
}
