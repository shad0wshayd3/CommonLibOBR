#pragma once

#include "UE/F/FStructuredArchiveSlotBase.h"

namespace UE
{
	class FStructuredArchiveMap :
		public StructuredArchive::Private::FSlotBase
	{
	public:
	};
	static_assert(sizeof(FStructuredArchiveMap) == 0x08);
}
