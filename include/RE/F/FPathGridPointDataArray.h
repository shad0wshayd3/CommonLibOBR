#pragma once

#include "RE/F/FPathGridPointData.h"
#include "RE/T/TArray.h"

namespace RE::UE
{
	class FPathGridPointDataArray
	{
	public:
		// members
		TArray<FPathGridPointData> array;  // 00
	};
	static_assert(sizeof(FPathGridPointDataArray) == 0x10);
}
