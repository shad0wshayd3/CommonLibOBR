#pragma once

namespace RE::UE
{
	template <class T, std::size_t... Args>
	class TIntegerSequence
	{
	public:
	};
	static_assert(std::is_empty_v<TIntegerSequence<std::uint32_t, 0>>);
}
