#pragma once

namespace RE
{
	enum class ACTOR_LIFE_STATE : std::int32_t
	{
		kAlive,
		kDying,
		kDead,
		kUnconscious,
		kReanimate,
		kRestrained,
		kEssentialDown,
	};
}
