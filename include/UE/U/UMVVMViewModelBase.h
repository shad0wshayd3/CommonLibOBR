#pragma once

#include "UE/I/INotifyFieldValueChanged.h"
#include "UE/M/MVVM_FMVVMFieldNotificationDelegates.h"
#include "UE/U/UObject.h"

namespace UE
{
	class UMVVMViewModelBase :
		public UObject,
		public INotifyFieldValueChanged
	{
	public:
		UE_DEFINE_UOBJECT(UMVVMViewModelBase, UObject, "/Script/ModelViewViewModel", "MVVMViewModelBase");

		// members
		MVVM::FMVVMFieldNotificationDelegates notificationDelegates;  // 30
	};
	static_assert(sizeof(UMVVMViewModelBase) == 0x68);
}
