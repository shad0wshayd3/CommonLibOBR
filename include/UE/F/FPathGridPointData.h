#pragma once

#include "UE/F/FVector.h"
#include "UE/T/TArray.h"

namespace UE
{
	class FPathGridPointData
	{
	public:
		// members
		std::int32_t         pointIndex;      // 00
		FVector              originalCoord;   // 08
		FVector              pointCoord;      // 20
		std::uint8_t         numConnections;  // 38
		TArray<std::int32_t> connections;     // 40
	};
	static_assert(sizeof(FPathGridPointData) == 0x50);
}
