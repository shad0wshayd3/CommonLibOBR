#pragma once

#include "RE/B/BSTList.h"

namespace RE
{
	class Tile;

	class HUDEffectIcon
	{
	public:
		// members
		Tile*                tile;    // 00
		BSSimpleList<void*>* fxList;  // 08 - BSSimpleList<ActiveEffect*>*
	};
	static_assert(sizeof(HUDEffectIcon) == 0x10);
}
