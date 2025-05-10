#pragma once

#include "RE/M/MagicSystem.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class TESEffectShader;
	class TESObjectLIGH;
	class TESSound;

	class EffectSetting :
		public TESForm,
		public TESModel,
		public TESDescription,
		public TESFullName,
		public TESIcon
	{
	public:
		inline static constexpr auto RTTI = RTTI::EffectSetting;
		inline static constexpr auto VTABLE = VTABLE::EffectSetting;
		inline static constexpr auto FORMTYPE = FormType::MagicEffect;

		struct EffectSettingData
		{
		public:
			// members
			std::uint32_t       flags;              // 00
			float               baseCost;           // 04
			std::uint32_t       associatedItem;     // 08
			MagicSystem::School magicSchool;        // 0C
			std::byte           resistVariable[4];  // 10
			std::uint16_t       numCounterEffects;  // 14
			TESObjectLIGH*      light;              // 18
			float               speed;              // 20
			TESEffectShader*    effectShader;       // 28
			TESEffectShader*    enchantEffect;      // 30
			TESSound*           castSound;          // 38
			TESSound*           boltSound;          // 40
			TESSound*           hitSound;           // 48
			TESSound*           areaSound;          // 50
			float               ceEnchantFactor;    // 58
			float               ceBarterFactor;     // 5C
		};
		static_assert(sizeof(EffectSettingData) == 0x60);

		using FilterValidationFunction_t = bool(EffectSetting*, void*);

		// members
		FilterValidationFunction_t* filterValidationFunction;   // 0A0
		void*                       filterValidationItem;       // 0A8
		EffectSettingData           data;                       // 0B0
		std::byte                   effectID[4];                // 110
		MagicSystem::EffectID*      counterEffects;             // 118
		std::int32_t                effectLoadedCount;          // 120
		std::int32_t                associatedItemLoadedCount;  // 124
	};
	static_assert(sizeof(EffectSetting) == 0x128);
}
