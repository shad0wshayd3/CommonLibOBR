#pragma once

namespace RE::UE
{
	template <class T, class U, std::size_t N>
	class BaseKeyFuncs
	{
	public:
	};
	static_assert(std::is_empty_v<BaseKeyFuncs<void*, void*, 0>>);
}
