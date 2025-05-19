#pragma once

#include "RE/M/MagicItem.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class MagicItemForm :
		public TESForm,
		public MagicItem
	{
	public:
		inline static constexpr auto RTTI = RTTI::MagicItemForm;
	};
	static_assert(sizeof(MagicItemForm) == 0x90);
}
