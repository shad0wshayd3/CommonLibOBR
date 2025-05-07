#pragma once

namespace RE
{
	enum class SCRIPT_BLOCK : std::int32_t
	{
		kGameMode,
		kMenuMode,
		kOnActivate,
		kOnAdd,
		kOnEquip,
		kOnUnequip,
		kOnDrop,
		kOnYield,
		kOnHit,
		kOnHitWith,
		kOnDeath,
		kOnMurder,
		kOnKnockout,
		kOnAlarm,
		kOnAlarmVictim,
		kOnPackageStart,
		kOnPackageEnd,
		kScriptEffectStart,
		kScriptEffectFinish,
		kScriptEffectUpdate,
		kOnPackageChange,
		kOnLoad,
		kOnMagicEffectHit,
		kOnSell,
		kOnTrigger,
		kOnStartCombat,
		kOnTriggerActor,
		kOnTriggerMob,
		kOnActorEquip,
		kOnActorUnequip,
		kOnReset,
		kOnDying
	};
}
