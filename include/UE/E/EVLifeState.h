#pragma once

namespace UE
{
	enum class EVLifeState : std::uint8_t
	{
		AliveFromSpawn = 0,
		AliveFromResurrection = 1,
		AliveFromUnconscious = 2,
		DeadFromSpawn = 3,
		DeadFromKilled = 4,
		Unconscious = 5,
	};
}
