#pragma once

#include "UE/F/FTickFunction.h"

namespace UE
{
	class UActorComponent;

	class FActorComponentTickFunction :
		public FTickFunction
	{
	public:
		// override
		virtual ~FActorComponentTickFunction();  // 00

		// override (FTickFunction)
		virtual void    ExecuteTick(float a_deltaTime, ELevelTick a_tickType, ENamedThreads a_currentThread, const FGraphEventRef& a_completionGraphEvent) override;  // 01
		virtual FString DiagnosticMessage() override;                                                                                                                 // 02
		virtual FName   DiagnosticContext(bool a_detailed) override;                                                                                                  // 03

		// members
		UActorComponent* target;  // 028
	};
	static_assert(sizeof(FActorComponentTickFunction) == 0x30);
}
