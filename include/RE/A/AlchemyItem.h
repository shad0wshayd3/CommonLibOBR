#pragma once

#include "RE/A/AlchemyItemData.h"
#include "RE/M/MagicItemObject.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESScriptableForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class AlchemyItem :
		public MagicItemObject,
		public TESModel,
		public TESIcon,
		public TESScriptableForm,
		public TESWeightForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::AlchemyItem;
		inline static constexpr auto VTABLE = VTABLE::AlchemyItem;
		inline static constexpr auto FORMTYPE = FormType::AlchemyItem;

		// members
		AlchemyItemData data;  // 118
	};
	static_assert(sizeof(AlchemyItem) == 0x120);
}
