#pragma once

#include "UE/T/TMulticastScriptDelegate.h"

namespace UE
{
	template <class InThreadSafetyMode, class R, class... Args>
	class TBaseDynamicMulticastDelegate :
		public TMulticastScriptDelegate<InThreadSafetyMode>
	{
	public:

	};
}
