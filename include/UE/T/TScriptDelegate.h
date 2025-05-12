#pragma once

#include "UE/F/FName.h"
#include "UE/F/FWeakObjectPtr.h"
#include "UE/T/TDelegateAccessHandlerBase.h"

namespace UE::Core::Private
{
	template <class InThreadSafetyMode>
	struct TScriptDelegateTraits
	{
		using WeakPtrType = FWeakObjectPtr;
		using ThreadSafetyMode = InThreadSafetyMode;
		using UnicastThreadSafetyModeForMulticasts = FNotThreadSafeNotCheckedDelegateMode;
	};
}

namespace UE
{
	template <class InThreadSafetyMode>
	class TScriptDelegate :
		public TDelegateAccessHandlerBase<typename Core::Private::TScriptDelegateTraits<InThreadSafetyMode>::ThreadSafetyMode>
	{
	public:
		using WeakPtrType = Core::Private::TScriptDelegateTraits<InThreadSafetyMode>::WeakPtrType;

		// members
		WeakPtrType object;
		FName       functionName;
	};
}
