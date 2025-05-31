#pragma once

#include "UE/T/TArray.h"

namespace UE::Scalability
{
	class FQualityLevels
	{
	public:
		// members
		float         resolutionQuality;          // 000
		std::int32_t  viewDistanceQuality;        // 004
		std::int32_t  antiAliasingQuality;        // 008
		std::int32_t  shadowQuality;              // 00C
		std::int32_t  globalIlluminationQuality;  // 010
		std::int32_t  reflectionQuality;          // 014
		std::int32_t  postProcessQuality;         // 018
		std::int32_t  textureQuality;             // 01C
		std::int32_t  effectsQuality;             // 020
		std::int32_t  foliageQuality;             // 024
		std::int32_t  shadingQuality;             // 028
		float         cpuBenchmarkResults;        // 02C
		float         gpuBenchmarkResults;        // 030
		TArray<float> cpuBenchmarkSteps;          // 038
		TArray<float> gpuBenchmarkSteps;          // 048
	};
	static_assert(sizeof(FQualityLevels) == 0x058);
}
