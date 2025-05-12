#pragma once

#include "UE/F/FRootMotionSourceSettings.h"
#include "UE/F/FVector_NetQuantize.h"
#include "UE/T/TArray.h"
#include "UE/T/TSharedPtr.h"

namespace UE
{
	class FRootMotionSource;

	class FRootMotionSourceGroup
	{
	public:
		// add
		virtual ~FRootMotionSourceGroup();  // 00

		// members
		TArray<TSharedPtr<FRootMotionSource>> rootMotionSources;                           // 008
		TArray<TSharedPtr<FRootMotionSource>> pendingAddRootMotionSources;                 // 018
		std::uint8_t                          hasAdditiveSources: 1;                       // 028:0
		std::uint8_t                          hasOverrideSources: 1;                       // 028:1
		std::uint8_t                          hasOverrideSourcesWithIgnoreZAccumulate: 1;  // 028:2
		std::uint8_t                          isAdditiveVelocityApplied: 1;                // 028:3
		FRootMotionSourceSettings             lastAccumulatedSettings;                     // 029
		FVector_NetQuantize10                 lastPreAdditiveVelocity;                     // 030
	};
	static_assert(sizeof(FRootMotionSourceGroup) == 0x48);
}
