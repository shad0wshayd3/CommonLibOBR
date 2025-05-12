#pragma once

#include "UE/T/TDelegateAccessHandlerBase.h"
#include "UE/T/TDelegateBase.h"

namespace UE
{
	struct FNotThreadSafeNotCheckedDelegateMode;

	using FMulticastInvocationListAllocatorType = FHeapAllocator;

	template <class Policy>
	class TMulticastDelegateBase :
		public TDelegateAccessHandlerBase<typename Policy::FThreadSafetyMode>
	{
	public:
		using UnicastDelegateType = TDelegateBase<FNotThreadSafeNotCheckedDelegateMode>;
		using InvocationListType = TArray<UnicastDelegateType, FMulticastInvocationListAllocatorType>;

		// members
		InvocationListType   invocationList;
		std::int32_t         compactionThreshold;
		mutable std::int32_t invocationListLockCount;
	};
}
