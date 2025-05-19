#pragma once

#include "UE/B/BaseKeyFuncs.h"

namespace UE
{
	template <class T, class U, std::size_t N>
	class TDefaultMapKeyFuncs
	{
	public:
	};
	static_assert(std::is_empty_v<TDefaultMapKeyFuncs<void*, void*, 0>>);
}
