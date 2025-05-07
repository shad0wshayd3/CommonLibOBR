#pragma once

#include "RE/B/BaseKeyFuncs.h"

namespace RE::UE
{
	template <class T, class U, std::size_t N>
	class TDefaultMapKeyFuncs
	{
	public:
	};
	static_assert(std::is_empty_v<TDefaultMapKeyFuncs<void*, void*, 0>>);
}
