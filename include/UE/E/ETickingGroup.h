#pragma once

namespace UE
{
	enum class ETickingGroup : std::int32_t
	{
		PrePhysics,
		StartPhysics,
		DuringPhysics,
		EndPhysics,
		PostPhysics,
		PostUpdateWork,
		LastDemotable,
		NewlySpawned,
	};
}
