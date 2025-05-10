#pragma once

namespace RE
{
	enum class SKILL_ACTION : std::int32_t
	{
		kBlock = 0,
		kRepair = 0,
		kAttack = 0,
		kCast = 0,
		kBargain = 0,
		kPersuasion = 0,
		kHitByOpponent = 0,
		kSecondOfRunning = 0,
		kPotionCreation = 0,
		kPickLock = 0,
		kAvoidNotice = 0,
		kJump = 0,
		kSecondOfSwimming = 1,
		kIngredientUse = 1,
		kPickPocket = 1,
		kFall = 1,
		kSpellHit = 1,
	};
}
