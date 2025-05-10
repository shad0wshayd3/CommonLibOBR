#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class IngredientItem;

	struct TESProduceForm :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESProduceForm;
		inline static constexpr auto VTABLE = VTABLE::TESProduceForm;

		// members
		IngredientItem* formIngredient;    // 08
		std::uint8_t    produceChance[4];  // 10
	};
	static_assert(sizeof(TESProduceForm) == 0x18);
}
