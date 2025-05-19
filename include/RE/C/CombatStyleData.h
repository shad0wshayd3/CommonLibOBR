#pragma once

namespace RE
{
	class CombatStyleData
	{
	public:
		// members
		std::uint8_t  dodgeChance;                     // 00
		std::uint8_t  dodgeLeftRightChance;            // 01
		float         dodgeLeftRightMinTime;           // 04
		float         dodgeLeftRightMaxTime;           // 08
		float         dodgeForwardMinTime;             // 0C
		float         dodgeForwardMaxTime;             // 10
		float         dodgeBackwardMinTime;            // 14
		float         dodgeBackwardMaxTime;            // 18
		float         idleMinTime;                     // 1C
		float         idleMaxTime;                     // 20
		std::uint8_t  blockChance;                     // 24
		std::uint8_t  attackChance;                    // 25
		float         attackDuringRecoilStaggerBonus;  // 28
		float         attackDuringUnconsciousBonus;    // 2C
		float         attackHandBonus;                 // 30
		std::uint8_t  powerAttackChance;               // 34
		float         powerAttackRecoilStaggerBonus;   // 38
		float         powerAttackUnconsciousBonus;     // 3C
		std::uint8_t  powerAttackNormalChance;         // 40
		std::uint8_t  powerAttackForwardChance;        // 41
		std::uint8_t  powerAttackBackwardChance;       // 42
		std::uint8_t  powerAttackLeftChance;           // 43
		std::uint8_t  powerAttackRightChance;          // 44
		float         holdMinTime;                     // 48
		float         holdMaxTime;                     // 4C
		std::uint8_t  flags;                           // 50
		std::uint8_t  acrobaticDodgeChance;            // 51
		float         optimalRangeMult;                // 54
		float         maximumRangeMult;                // 58
		float         switchToMeleeDistance;           // 5C
		float         switchToRangedDistance;          // 60
		float         buffStandoffDistance;            // 64
		float         rangedStandoffDistance;          // 68
		float         groupStandoffDistance;           // 6C
		std::uint8_t  rushingAttackPercentChance;      // 70
		float         rushingAttackDistanceMult;       // 74
		std::uint32_t newFlags;                        // 78
	};
	static_assert(sizeof(CombatStyleData) == 0x7C);
}
