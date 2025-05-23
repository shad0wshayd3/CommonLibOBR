#pragma once

namespace UE
{
	enum class EGrassWaterState : std::uint32_t
	{
		AboveOnlyAtLeast = 0,
		AboveOnlyAtMost = 1,
		BelowOnlyAtLeast = 2,
		BelowOnlyAtMost = 3,
		BothAtLeast = 4,
		BothAtMost = 5,
		BothAtMostAbove = 6,
		BothAtMostBelow = 7,
	};
}
