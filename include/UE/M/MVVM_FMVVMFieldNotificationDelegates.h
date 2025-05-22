#pragma once

#include "UE/F/FieldNotification_FFieldMulticastDelegate.h"
#include "UE/T/TBitArray.h"

namespace UE
{
	namespace MVVM
	{
		class FMVVMFieldNotificationDelegates
		{
		public:
			// members
			FieldNotification::FFieldMulticastDelegate delegates;                  // 00
			TBitArray<FDefaultBitArrayAllocator>       enabledFieldNotifications;  // 18
		};
		static_assert(sizeof(FMVVMFieldNotificationDelegates) == 0x38);
	}
}
