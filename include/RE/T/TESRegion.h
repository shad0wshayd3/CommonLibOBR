#pragma once

#include "RE/B/BSTList.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class TESRegionDataList;
	class TESRegionPointList;
	class TESWeather;
	class TESWorldSpace;

	class TESRegion :
		public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESRegion;
		inline static constexpr auto VTABLE = VTABLE::TESRegion;
		inline static constexpr auto FORMTYPE = FormType::Region;

		// members
		TESRegionDataList*                 data;               // 30
		BSSimpleList<TESRegionPointList*>* points;             // 38
		TESWorldSpace*                     worldSpace;         // 40
		TESWeather*                        currentWeather;     // 48
		float                              lastWeatherUpdate;  // 50
	};
	static_assert(sizeof(TESRegion) == 0x58);
}
