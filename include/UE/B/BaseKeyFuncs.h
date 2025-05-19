#pragma once

namespace UE
{
	template <class T, class U, bool D>
	class BaseKeyFuncs
	{
	public:
	};
	static_assert(std::is_empty_v<BaseKeyFuncs<void*, void*, false>>);
}
