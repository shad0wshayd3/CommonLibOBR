#pragma once

#include "RE/E/EnchantmentItemData.h"
#include "RE/M/MagicItemForm.h"

namespace RE
{
	class EnchantmentItem :
		public MagicItemForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::EnchantmentItem;
		inline static constexpr auto VTABLE = VTABLE::EnchantmentItem;
		inline static constexpr auto FORMTYPE = FormType::Enchantment;

		// members
		EnchantmentItemData data;  // 90
	};
	static_assert(sizeof(EnchantmentItem) == 0xA0);
}
