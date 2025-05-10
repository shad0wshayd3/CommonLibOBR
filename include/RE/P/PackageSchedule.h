#pragma once

#include "RE/P/PACK_SCHED_DATA.h"

namespace RE
{
	class PackageSchedule
	{
	public:
		// members
		PACK_SCHED_DATA data;  // 00
	};
	static_assert(sizeof(PackageSchedule) == 0x08);
}
