#pragma once

#include "RE/C/CREATURE_DATA.h"
#include "RE/T/TESActorBase.h"
#include "RE/T/TESAttackDamageForm.h"
#include "RE/T/TESModelList.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class CreatureSounds;
	class TESCombatStyle;

	class TESCreature :
		public TESActorBase,
		public TESAttackDamageForm,
		public TESModelList
	{
	private:
		// members
		union sound_t
		{
			TESCreature*    soundCreature;
			CreatureSounds* creatureSounds;
		};

	public:
		inline static constexpr auto RTTI = RTTI::TESCreature;
		inline static constexpr auto VTABLE = VTABLE::TESCreature;
		inline static constexpr auto FORMTYPE = FormType::Creature;

		// members
		sound_t         sounds;             // 1E0
		CREATURE_DATA   data;               // 1E8
		std::uint8_t    handReach;          // 1EE
		float           turnSpeed;          // 1F0
		float           footWeight;         // 1F4
		float           baseScale;          // 1F8
		TESCombatStyle* combatStyle;        // 200
		TESModel        bloodSprayModel;    // 208
		TESTexture      bloodDecalTexture;  // 238
	};
	static_assert(sizeof(TESCreature) == 0x250);
}
