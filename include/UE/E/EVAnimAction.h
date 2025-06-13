#pragma once

namespace UE
{
	enum class EVAnimAction : std::uint8_t
	{
		None = 0,
		EquipWeapon = 1,
		UnequipWeapon = 2,
		Attack = 3,
		AttackFollowThrough = 4,
		AttackBow = 5,
		AttackBowArrowAttached = 6,
		Block = 7,
		Recoil = 8,
		Stagger = 9,
		Dodge = 10,
		WaitForLowerBodyAnim = 11,
		WaitForSpecialIdle = 12,
		ForceScriptAnim = 13,
	};
}
