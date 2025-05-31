#pragma once

namespace UE
{
	enum class EEndPlayReason : std::int32_t
	{
		Destroyed = 0,
		LevelTransition = 1,
		EndPlayInEditor = 2,
		RemovedFromWorld = 3,
		Quit = 4
	};
}
