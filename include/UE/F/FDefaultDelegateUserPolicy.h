#pragma once

#include "UE/I/IDelegateInstance.h"
#include "UE/T/TMulticastDelegateBase.h"

namespace UE
{
	struct FNotThreadSafeDelegateMode;

	struct FDefaultDelegateUserPolicy
	{
		using FThreadSafetyMode = FNotThreadSafeDelegateMode;
		using FDelegateExtras = TDelegateBase<FThreadSafetyMode>;
		using FDelegateInstanceExtras = IDelegateInstance;
		using FMulticastDelegateExtras = TMulticastDelegateBase<FDefaultDelegateUserPolicy>;
	};
}
