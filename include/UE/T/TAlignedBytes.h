#pragma once

namespace UE
{
	template <std::int32_t N, std::uint32_t A>
	class TAlignedBytes
	{
	public:
		// members
		alignas(A) std::uint8_t pad[N];  // 00
	};
	static_assert(sizeof(TAlignedBytes<1, 1>) == 0x01);
}
