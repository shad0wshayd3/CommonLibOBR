#pragma once

#include "RE/T/TESModel.h"

namespace RE
{
	struct TESModelAnim :
		public TESModel
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESModelAnim;
	};
	static_assert(sizeof(TESModelAnim) == 0x30);
}
