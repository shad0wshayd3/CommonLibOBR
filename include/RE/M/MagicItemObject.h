#pragma once

#include "RE/M/MagicItem.h"
#include "RE/T/TESBoundObject.h"

namespace RE
{
	class MagicItemObject :
		public TESBoundObject,
		public MagicItem
	{
	public:
		inline static constexpr auto RTTI = RTTI::MagicItemObject;
		inline static constexpr auto VTABLE = VTABLE::MagicItemObject;
	};
	static_assert(sizeof(MagicItemObject) == 0xA8);
}
