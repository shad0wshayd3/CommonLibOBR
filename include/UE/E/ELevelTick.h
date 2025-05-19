#pragma once

namespace UE
{
	enum class ELevelTick : std::int32_t
	{
		TimeOnly = 0,
		ViewportsOnly = 1,
		All = 2,
		PauseTick = 3,
	};
}
