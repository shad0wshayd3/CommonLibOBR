#pragma once

#include "RE/T/TDefaultMapKeyFuncs.h"

namespace RE::UE
{
	template <class T, class U, std::size_t N>
	class TDefaultMapHashableKeyFuncs :
		public TDefaultMapKeyFuncs<T, U, N>
	{
	public:
	};
	static_assert(std::is_empty_v<TDefaultMapHashableKeyFuncs<void*, void*, 0>>);
}
