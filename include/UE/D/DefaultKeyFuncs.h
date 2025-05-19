#pragma once

#include "UE/B/BaseKeyFuncs.h"

namespace UE
{
	template <class T, bool D = false>
	class DefaultKeyFuncs :
		public BaseKeyFuncs<T, T, D>
	{
	public:
	};
	static_assert(std::is_empty_v<DefaultKeyFuncs<void*>>);
}
