#pragma once

namespace UE
{
	enum class ESpawnActorCollisionHandlingMethod : std::uint8_t
	{
		Undefined,
		AlwaysSpawn,
		AdjustIfPossibleButAlwaysSpawn,
		AdjustIfPossibleButDontSpawnIfColliding,
		DontSpawnIfColliding,
	};
}
