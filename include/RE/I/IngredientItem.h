#pragma once

#include "RE/I/IngredientItemData.h"
#include "RE/M/MagicItemObject.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESScriptableForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class IngredientItem :
		public MagicItemObject,
		public TESModel,
		public TESIcon,
		public TESScriptableForm,
		public TESWeightForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::IngredientItem;
		inline static constexpr auto VTABLE = VTABLE::IngredientItem;
		inline static constexpr auto FORMTYPE = FormType::Ingredient;

		// members
		IngredientItemData data;  // 118
	};
	static_assert(sizeof(IngredientItem) == 0x120);
}
