#pragma once

namespace UE
{
	template <class T>
	class TFunctionRef;

	class UClass;

	namespace FieldNotification
	{
		class FFieldId;

		class IClassDescriptor
		{
		public:
			// add
			virtual void ForEachField(const UClass*, TFunctionRef<bool(FFieldId)>);  // 00
			virtual ~IClassDescriptor();                                             // 01
		};
		static_assert(sizeof(IClassDescriptor) == 0x08);
	}
}
