#pragma once

namespace UE
{
	template <class T>
	class TTypeCompatibleBytes
	{
	public:
		// members
		alignas(T) std::uint8_t pad[sizeof(T)];  // 00
	};
	static_assert(sizeof(TTypeCompatibleBytes<std::uint32_t>) == 0x04);
}
