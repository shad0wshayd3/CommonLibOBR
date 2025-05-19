#pragma once

#include "UE/F/FStructuredArchiveSlotBase.h"

namespace UE
{
	class FStructuredArchiveRecord :
		public StructuredArchive::Private::FSlotBase
	{
	public:
	};
	static_assert(sizeof(FStructuredArchiveRecord) == 0x08);
}
