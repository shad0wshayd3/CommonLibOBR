#pragma once

#include "UE/F/FStructuredArchiveSlotBase.h"

namespace UE
{
	class FStructuredArchiveArray :
		public StructuredArchive::Private::FSlotBase
	{
	public:
	};
	static_assert(sizeof(FStructuredArchiveArray) == 0x08);
}
