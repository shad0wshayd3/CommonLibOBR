#pragma once

#include "RE/R/REGION_DATA_ID.h"

namespace RE
{
	class TESFile;                 // TODO
	class TESRegionData;           // TODO
	class TESRegionDataGrass;      // TODO
	class TESRegionDataLandscape;  // TODO
	class TESRegionDataMap;        // TODO
	class TESRegionDataObjects;    // TODO
	class TESRegionDataSound;      //TODO
	class TESRegionDataWeather;    // TODO
	class TESRegion;

	class TESRegionDataManager
	{
	public:
		virtual ~TESRegionDataManager();  // 00

		// add
		virtual TESRegion*              GetLastLoadedRegion();                                 // 01
		virtual TESRegionData*          ConstructRegionData(REGION_DATA_ID a_type);            // 02
		virtual TESRegionDataObjects*   IsRegionDataObjects(TESRegionData* a_data);            // 03
		virtual TESRegionDataWeather*   IsRegionDataWeather(TESRegionData* a_data);            // 04
		virtual TESRegionDataMap*       IsRegionDataMap(TESRegionData* a_data);                // 05
		virtual TESRegionDataLandscape* IsRegionDataLandscape(TESRegionData* a_data);          // 06
		virtual TESRegionDataGrass*     IsRegionDataGrass(TESRegionData* a_data);              // 07
		virtual TESRegionDataSound*     IsRegionDataSound(TESRegionData* a_data);              // 08
		virtual bool                    LoadRegionData(TESFile* a_file, TESRegion* a_region);  // 09

		// members
		TESRegion* lastLoadedRegion;  // 08
	};
	static_assert(sizeof(TESRegionDataManager) == 0x10);
}
