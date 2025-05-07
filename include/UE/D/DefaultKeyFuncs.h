#pragma once

#include "UE/B/BaseKeyFuncs.h"

namespace UE
{
	template <class T, std::size_t N>
	class DefaultKeyFuncs :
		public BaseKeyFuncs<T, T, N>
	{
	public:
	};
	static_assert(std::is_empty_v<DefaultKeyFuncs<void*, 0>>);
}
