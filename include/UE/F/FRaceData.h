#pragma once

#include "UE/T/TArray.h"

namespace UE
{
	class FRaceData
	{
	public:
		// members
		TArray<float> height;  // 00
	};
	static_assert(sizeof(FRaceData) == 0x10);
}
