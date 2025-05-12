#pragma once

#include "UE/T/TArray.h"
#include "UE/T/TScriptDelegate.h"

namespace UE
{
	template <class InThreadSafetyMode>
	class TMulticastScriptDelegate :
		public TDelegateAccessHandlerBase<typename Core::Private::TScriptDelegateTraits<InThreadSafetyMode>::ThreadSafetyMode>
	{
		using UnicastDelegateType = TScriptDelegate<typename Core::Private::TScriptDelegateTraits<InThreadSafetyMode>::UnicastThreadSafetyModeForMulticasts>;
		using InvocationListType = TArray<UnicastDelegateType>;

	public:
		// members
		mutable InvocationListType invocationList;
	};
}
