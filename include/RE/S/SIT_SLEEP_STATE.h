#pragma once

namespace RE
{
	enum class SIT_SLEEP_STATE : std::int32_t
	{
		kNormal,
		kLoadSitIdle,
		kWantToSit,
		kWaitingForSitAnim,
		kIsSitting,
		kWantToStand,
		kLoadSleepIdle,
		kWantToSleep,
		kWaitingForSleepAnim,
		kIsSleeping,
		kWantToWake,
	};
}
