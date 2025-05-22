#pragma once

#include "UE/F/FNotThreadSafeNotCheckedDelegateUserPolicy.h"
#include "UE/I/IInterface.h"
#include "UE/T/TDelegate.h"

namespace UE
{
	class FDelegateHandle;
	class UObject;

	namespace FieldNotification
	{
		class FFieldId;
		class IClassDescriptor;
	}

	class INotifyFieldValueChanged :
		public IInterface
	{
	public:
		// override
		virtual ~INotifyFieldValueChanged();                                                                                                                                                                               // 00
		virtual UObject*                                   GetUObject();                                                                                                                                                   // 01
		virtual FDelegateHandle*                           AddFieldValueChangedDelegate(FieldNotification::FFieldId, TDelegate<void(UObject*, FieldNotification::FFieldId), FNotThreadSafeNotCheckedDelegateUserPolicy>);  // 02
		virtual bool                                       RemoveFieldValueChangedDelegate(FieldNotification::FFieldId, FDelegateHandle);                                                                                  // 03
		virtual std::int32_t                               RemoveAllFieldValueChangedDelegates(FieldNotification::FFieldId, const void*);                                                                                  // 04
		virtual std::int32_t                               RemoveAllFieldValueChangedDelegates(const void*);                                                                                                               // 05
		virtual const FieldNotification::IClassDescriptor* GetFieldNotificationDescriptor();                                                                                                                               // 06
		virtual void                                       BroadcastFieldValueChanged(FieldNotification::FFieldId);                                                                                                        // 07
	};
	static_assert(sizeof(INotifyFieldValueChanged) == 0x08);
}
