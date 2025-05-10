#pragma once

namespace RE
{
	class AlchemyItemData
	{
	public:
		// members
		std::int32_t costOverride;  // 00
		std::uint8_t flags;         // 04
	};
	static_assert(sizeof(AlchemyItemData) == 0x08);
}
