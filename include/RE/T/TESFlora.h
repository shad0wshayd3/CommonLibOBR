#pragma once

#include "RE/T/TESObjectACTI.h"
#include "RE/T/TESProduceForm.h"

namespace RE
{
	class TESFlora :
		public TESProduceForm,
		public TESObjectACTI
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESFlora;
		inline static constexpr auto VTABLE = VTABLE::TESFlora;
		inline static constexpr auto FORMTYPE = FormType::Flora;
	};
	static_assert(sizeof(TESFlora) == 0xC8);
}
