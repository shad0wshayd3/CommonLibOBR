#pragma once

#include "RE/E/EffectItemList.h"
#include "RE/T/TESObjectMISC.h"
#include "RE/T/TESUsesForm.h"

namespace RE
{
	class TESSigilStone :
		public TESObjectMISC,
		public TESUsesForm,
		public EffectItemList
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESSigilStone;
		inline static constexpr auto VTABLE = VTABLE::TESSigilStone;
		inline static constexpr auto FORMTYPE = FormType::SigilStone;
	};
	static_assert(sizeof(TESSigilStone) == 0x110);
}
