#pragma once

#include "UE/E/ELevelTick.h"
#include "UE/E/ENamedThreads.h"
#include "UE/E/ETickingGroup.h"
#include "UE/F/FGraphEvent.h"
#include "UE/F/FName.h"
#include "UE/F/FString.h"
#include "UE/T/TArray.h"
#include "UE/T/TEnumAsByte.h"
#include "UE/T/TUniquePtr.h"

namespace UE
{
	class FBaseGraphTask;
	class FTickTaskLevel;
	class FTickPrerequisite;

	class FTickFunction
	{
	public:
		enum class ETickState : std::uint8_t
		{
			Disabled,
			Enabled,
			CoolingDown
		};

		struct FInternalData
		{
			// members
			bool                       registered: 1;
			bool                       wasInterval: 1;
			TEnumAsByte<ETickingGroup> actualStartTickGroup;
			TEnumAsByte<ETickingGroup> actualEndTickGroup;
			std::int32_t               tickVisitedGFrameCounter;
			std::atomic<std::int32_t>  tickQueuedGFrameCounter;
			FBaseGraphTask*            taskPointer;
			FTickFunction*             next;
			float                      relativeTickCooldown;
			float                      lastTickGameTimeSeconds;
			FTickTaskLevel*            tickTaskLevel;
		};

		// add
		virtual ~FTickFunction();  // 00

		// add
		virtual void    ExecuteTick(float a_deltaTime, ELevelTick a_tickType, ENamedThreads a_currentThread, const FGraphEventRef& a_completionGraphEvent) = 0;  // 01
		virtual FString DiagnosticMessage() = 0;                                                                                                                 // 02
		virtual FName   DiagnosticContext(bool a_detailed);                                                                                                      // 03

		// members
		TEnumAsByte<ETickingGroup> tickGroup;                      // 08
		TEnumAsByte<ETickingGroup> endTickGroup;                   // 09
		std::uint8_t               tickEvenWhenPaused: 1;          // 0A:0
		std::uint8_t               canEverTick: 1;                 // 0A:1
		std::uint8_t               startWithTickEnabled: 1;        // 0A:2
		std::uint8_t               allowTickOnDedicatedServer: 1;  // 0A:3
		std::uint8_t               highPriority: 1;                // 0A:4
		std::uint8_t               runOnAnyThread: 1;              // 0A:5
		ETickState                 tickState;                      // 0B
		float                      tickInterval;                   // 0C
		TArray<FTickPrerequisite>  prerequisites;                  // 10
		TUniquePtr<FInternalData>  internalData;                   // 20
	};
	static_assert(sizeof(FTickFunction) == 0x28);
}
