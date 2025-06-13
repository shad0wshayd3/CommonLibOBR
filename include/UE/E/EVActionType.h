#pragma once

namespace UE
{
	enum class EVActionType : std::uint8_t
	{
		PowerAttack = 0,
		RightAttack = 1,
		LeftAttack = 2,
		PowerAttackForward = 3,
		PowerAttackBack = 4,
		PowerAttackRight = 5,
		PowerAttackLeft = 6,
		BowDraw = 7,
		BowShoot = 8,
		DrawWeapon = 9,
		PrepareAttack = 10,
		Block = 11,
		Jump = 12,
		BlockHit = 13,
		Recoil = 14,
		Stagger = 15,
		SpellCasting = 16,
		DodgeForward = 17,
		DodgeBack = 18,
		DodgeRight = 19,
		DodgeLeft = 20,
	};
}
