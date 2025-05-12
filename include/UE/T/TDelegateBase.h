#pragma once

#include "UE/T/TAlignedBytes.h"
#include "UE/T/TSizedHeapAllocator.h"

namespace UE
{
	using FAlignedInlineDelegateType = TAlignedBytes<16, 16>;
	using FDelegateAllocatorType = FHeapAllocator;

	template <class ThreadSafetyMode>
	class TDelegateBase :
		public TDelegateAccessHandlerBase<ThreadSafetyMode>
	{
		template <class>
		friend class TMulticastDelegateBase;

	public:
		// members
		FDelegateAllocatorType::ForElementType<FAlignedInlineDelegateType> delegateAllocator;
		std::int32_t                                                       delegateSize = 0;
	};
}
