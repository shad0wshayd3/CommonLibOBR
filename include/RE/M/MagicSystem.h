#pragma once

namespace RE
{
	namespace MagicSystem
	{
		enum class CastingType : std::int32_t
		{
			kCastOnce,
			kWhenUsed,
			kWhenStrikes,
			kConstantEffect,
		};

		enum class EffectID : std::int8_t;

		enum class FlareType : std::int32_t
		{
			kNone = 0,
			kFire = 1 << 0,
			kFrost = 1 << 1,
			kShock = 1 << 2,
			kWeapon = 1 << 3,
		};

		enum class ProjectileType : std::int32_t
		{
			kBall,
			kBolt,
			kSpray,
			kFog,
		};

		enum class Range : std::int32_t
		{
			kSelf,
			kTouch,
			kTarget,
		};

		enum class School : std::int32_t
		{
			kAlteration,
			kConjuration,
			kDestruction,
			kIllusion,
			kMysticism,
			kRestoration,
		};

		enum class SpellType : std::int32_t
		{
			kSpell,
			kDisease,
			kPower,
			kLesserPower,
			kAbility,
			kPoison,
			kEnchantment,
			kPotion,
			kWortcraft,
			kLeveledSpell,
		};
	}
}
