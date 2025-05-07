#pragma once

namespace RE::UE
{
	template <std::size_t N, std::size_t O>
	class TAlignedBytes
	{
	public:
		// members
		std::uint8_t pad[N];  // 00
	};
	static_assert(sizeof(TAlignedBytes<1, 1>) == 0x01);
}
