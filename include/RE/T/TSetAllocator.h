#pragma once

namespace RE::UE
{
	template <class T, class U, std::size_t N, std::size_t O, std::size_t P>
	class TSetAllocator
	{
	public:
	};
	static_assert(std::is_empty_v<TSetAllocator<void*, void*, 0, 0, 0>>);
}
