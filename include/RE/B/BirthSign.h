#pragma once

#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESSpellList.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class BirthSign :
		public TESForm,
		public TESFullName,
		public TESTexture,
		public TESDescription,
		public TESSpellList
	{
	public:
		inline static constexpr auto RTTI = RTTI::BirthSign;
		inline static constexpr auto VTABLE = VTABLE::BirthSign;
		inline static constexpr auto FORMTYPE = FormType::BirthSign;
	};
	static_assert(sizeof(BirthSign) == 0x98);
}
