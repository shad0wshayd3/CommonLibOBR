#pragma once

namespace UE
{
	enum class EAutoPossessAI : std::uint8_t
	{
		Disabled,
		PlacedInWorld,
		Spawned,
		PlacedInWorldOrSpawned,
	};
}
