#pragma once

namespace UE
{
	class FVBuoyancySettings
	{
	public:
		// members
		bool  doesGeneratePontoonsAtRuntime;  // 000
		bool  needsOrientationAdjustment;     // 001
		float generatedPontoonSizeScale;      // 004
		float buoyancyCoefficient;            // 008
	};
	static_assert(sizeof(FVBuoyancySettings) == 0xC);
}
