#pragma once

#include "RE/T/TESObjectMISC.h"

namespace RE
{
	class TESKey :
		public TESObjectMISC
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESKey;
		inline static constexpr auto VTABLE = VTABLE::TESKey;
		inline static constexpr auto FORMTYPE = FormType::KeyMaster;
	};
	static_assert(sizeof(TESKey) == 0xE0);
}
