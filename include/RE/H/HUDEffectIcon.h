#pragma once

#include "RE/B/BSTList.h"

namespace RE
{
	class ActiveEffect;
	class Tile;

	class HUDEffectIcon
	{
	public:
		// members
		Tile*                        tile;    // 00
		BSSimpleList<ActiveEffect*>* fxList;  // 08
	};
	static_assert(sizeof(HUDEffectIcon) == 0x10);
}
