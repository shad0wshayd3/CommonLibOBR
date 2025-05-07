#pragma once

#include "RE/T/TArray.h"
#include "RE/T/TVector.h"

namespace RE::UE
{
	class FPathGridPointData
	{
	public:
		// members
		std::int32_t          pointIndex;      // 00
		Math::TVector<double> originalCoord;   // 08
		Math::TVector<double> pointCoord;      // 20
		std::uint8_t          numConnections;  // 38
		TArray<std::int32_t>  connections;     // 40
	};
	static_assert(sizeof(FPathGridPointData) == 0x50);
}
