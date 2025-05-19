#pragma once

#include "RE/B/BSTList.h"

namespace RE
{
	class ActiveEffect;
	class MagicCaster;
	class MagicItem;
	class TESObjectREFR;

	class MagicTarget
	{
	public:
		inline static constexpr auto RTTI = RTTI::MagicTarget;
		inline static constexpr auto VTABLE = VTABLE::MagicTarget;

		// add
		virtual bool                         AddTarget(MagicCaster* a_caster, MagicItem* a_spell, ActiveEffect* a_activeEffect, bool a_areaTarget);       // 00
		virtual TESObjectREFR*               GetTargetStatsObject();                                                                                      // 01
		virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList();                                                                                       // 02
		virtual bool                         MagicTargetIsActor();                                                                                        // 03
		virtual void                         EffectAdded(ActiveEffect* a_effect);                                                                         // 04
		virtual void                         EffectRemoved(ActiveEffect* a_effect);                                                                       // 05
		virtual void                         EffectReflected(MagicCaster* a_caster, ActiveEffect* a_effect);                                              // 06
		virtual void                         EffectAbsorbed(MagicCaster* a_caster, ActiveEffect* a_effect);                                               // 07
		virtual float                        CheckResistance(MagicCaster* a_caster, MagicItem* a_spell, ActiveEffect* a_activeEffect);                    // 08
		virtual bool                         CheckAbsorb(MagicCaster* a_caster, MagicItem* a_spell, ActiveEffect* a_activeEffect, bool a_reducedChance);  // 09
		virtual bool                         CheckReflect(MagicCaster* a_caster, MagicItem* a_spell, ActiveEffect* a_activeEffect);                       // 0A

		// members
		bool showTargetStats;  // 08
	};
	static_assert(sizeof(MagicTarget) == 0x10);
}
