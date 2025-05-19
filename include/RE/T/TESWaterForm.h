#pragma once

#include "RE/B/BSStringT.h"
#include "RE/T/TESAttackDamageForm.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESTexture.h"
#include "RE/W/WaterShaderData.h"

namespace RE
{
	class TESSound;

	class TESWaterForm :
		public TESForm,
		public TESAttackDamageForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESWaterForm;
		inline static constexpr auto VTABLE = VTABLE::TESWaterForm;
		inline static constexpr auto FORMTYPE = FormType::Water;

		// members
		TESTexture      waterTexture;            // 40
		std::uint8_t    alpha;                   // 58
		std::uint8_t    flags;                   // 59
		BSString        materialID;              // 60
		TESSound*       waterSound;              // 70
		WaterShaderData data;                    // 78
		TESWaterForm*   waterWeatherControl[3];  // E0
	};
	static_assert(sizeof(TESWaterForm) == 0xF8);
}
