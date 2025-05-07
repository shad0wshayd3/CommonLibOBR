#pragma once

#include "UE/F/FPathGridPointData.h"
#include "UE/T/TArray.h"

namespace UE
{
	class FPathGridPointDataArray
	{
	public:
		// members
		TArray<FPathGridPointData> array;  // 00
	};
	static_assert(sizeof(FPathGridPointDataArray) == 0x10);
}
