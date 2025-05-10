#pragma once

namespace RE
{
	class IngredientItemData
	{
	public:
		// members
		std::int32_t costOverride;  // 00
		std::uint8_t flags;         // 04
	};
	static_assert(sizeof(IngredientItemData) == 0x08);
}
