#pragma once

#include "UE/F/FStructuredArchiveSlotBase.h"

namespace UE
{
	class FStructuredArchiveStream :
		public StructuredArchive::Private::FSlotBase
	{
	public:
	};
	static_assert(sizeof(FStructuredArchiveStream) == 0x08);
}
