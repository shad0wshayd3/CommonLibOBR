#pragma once

#include "UE/T/TMulticastDelegateBase.h"

namespace UE
{
	struct FNotThreadSafeDelegateMode;

	struct FDefaultDelegateUserPolicy
	{
		using FThreadSafetyMode = FNotThreadSafeDelegateMode;
		using FMulticastDelegateExtras = TMulticastDelegateBase<FDefaultDelegateUserPolicy>;
	};
}
