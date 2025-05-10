#pragma once

#include "RE/B/BSTList.h"
#include "RE/N/NiTPointerMap.h"

namespace RE
{
	class TESTerrainLODQuadRoot;
	class TESWorldSpace;
	class TLODVert;

	class TESTerrainLODManager
	{
	public:
		// members
		NiTPointerMap<std::int32_t, TESTerrainLODQuadRoot*> lodMap;       // 00
		TESWorldSpace*                                      worldSpace;   // 20
		BSSimpleList<TLODVert*>                             alteredList;  // 28
	};
	static_assert(sizeof(TESTerrainLODManager) == 0x38);
}
