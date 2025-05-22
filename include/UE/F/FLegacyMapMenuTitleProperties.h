#pragma once

#include "UE/F/FText.h"

namespace UE
{
	class FLegacyMapMenuTitleProperties
	{
	public:
		// members
		FText location;  // 00
		FText date;      // 18
	};
	static_assert(sizeof(FLegacyMapMenuTitleProperties) == 0x30);
}
