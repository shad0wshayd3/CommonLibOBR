#pragma once

#include "RE/B/BSTList.h"
#include "RE/T/TESRegion.h"

namespace RE
{
	class TESRegionList :
		public BSSimpleList<TESRegion*>
	{
	public:
		virtual ~TESRegionList();  // 00

		// members
		bool ownsRegionMemory;  // 18
	};
	static_assert(sizeof(TESRegionList) == 0x20);
}
