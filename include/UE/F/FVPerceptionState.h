#pragma once

#include "UE/E/EVVisiblePart.h"

namespace UE
{
	class FVPerceptionState
	{
	public:
		// members
		EVVisiblePart visiblePart;  // 000
		bool          lineOfSight;  // 001
	};
	static_assert(sizeof(FVPerceptionState) == 0x2);
}
