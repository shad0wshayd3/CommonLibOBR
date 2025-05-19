#pragma once

#include "UE/T/TScriptDelegate.h"

namespace UE
{
	template <class InThreadSafetyMode, class R, class... Args>
	class TBaseDynamicDelegate :
		public TScriptDelegate<InThreadSafetyMode>
	{
	public:
	};
}
