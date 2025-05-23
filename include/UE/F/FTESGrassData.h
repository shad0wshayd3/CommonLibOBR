#pragma once

#include "UE/E/EGrassWaterState.h"

namespace UE
{
	class FTESGrassData
	{
	public:
		// members
		std::uint8_t     density;                 // 000
		std::uint8_t     minSlopeDegrees;         // 001
		std::uint8_t     maxxSlopeDegrees;        // 002
		std::int32_t     distanceFromWaterLevel;  // 004
		EGrassWaterState underwater;              // 008
		float            positionRange;           // 00C
		float            heightRange;             // 010
		float            colorRange;              // 014
		float            wavePeriod;              // 018
		std::uint8_t     flags;                   // 01C
	};
	static_assert(sizeof(FTESGrassData) == 0x20);
}
