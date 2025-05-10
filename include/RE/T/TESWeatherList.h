#pragma once

#include "RE/B/BSTList.h"

namespace RE
{
	class WeatherEntry;

	struct TESWeatherList :
		public BSSimpleList<WeatherEntry*>
	{
	public:
	};
	static_assert(sizeof(TESWeatherList) == 0x10);
}
