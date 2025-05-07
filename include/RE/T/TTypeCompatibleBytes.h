#pragma once

namespace RE::UE
{
	template <class T>
	class TTypeCompatibleBytes
	{
	public:
		// members
		std::uint8_t pad[sizeof(T)];  // 00
	};
	static_assert(sizeof(TTypeCompatibleBytes<std::uint32_t>) == 0x04);
}
