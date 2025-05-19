#pragma once

#include "RE/A/AMMO_DATA.h"
#include "RE/T/TESAttackDamageForm.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESEnchantableForm.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class TESAmmo :
		public TESBoundObject,
		public TESFullName,
		public TESModel,
		public TESIcon,
		public TESEnchantableForm,
		public TESValueForm,
		public TESWeightForm,
		public TESAttackDamageForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESAmmo;
		inline static constexpr auto VTABLE = VTABLE::TESAmmo;
		inline static constexpr auto FORMTYPE = FormType::Ammo;

		// members
		AMMO_DATA data;  // F0
	};
	static_assert(sizeof(TESAmmo) == 0xF8);
}
