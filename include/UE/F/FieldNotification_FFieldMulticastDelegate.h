#pragma once

#include "UE/F/FName.h"
#include "UE/F/FNotThreadSafeNotCheckedDelegateUserPolicy.h"
#include "UE/F/FieldNotification_FFieldId.h"
#include "UE/T/TArray.h"
#include "UE/T/TDelegate.h"
#include "UE/T/TWeakObjectPtr.h"

namespace UE
{
	class UObject;

	namespace FieldNotification
	{
		class FFieldMulticastDelegate
		{
		public:
			class FInvocationKey
			{
			public:
				// members
				TWeakObjectPtr<const UObject> object;       // 00
				FFieldId                      id;           // 08
				FName                         dynamicName;  // 14
			};
			static_assert(sizeof(FInvocationKey) == 0x1C);

			class FInvocationElement
			{
			public:
				// members
				FInvocationKey                                                                  key;       // 00
				std::byte                                                                       pad1C[4];  // 1C
				TDelegate<void(UObject*, FFieldId), FNotThreadSafeNotCheckedDelegateUserPolicy> delegate;  // 20
			};
			// static_assert(sizeof(FInvocationElement) == 0x30);

			// members
			TArray<FInvocationElement> delegates;          // 00
			std::int16_t               delegateLockCount;  // 10
			std::int16_t               compactionCount;    // 12
			std::uint16_t              addedEmplaceAt;     // 14
		};
		static_assert(sizeof(FFieldMulticastDelegate) == 0x18);
	}
}
