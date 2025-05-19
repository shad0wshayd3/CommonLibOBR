#pragma once

#include "UE/E/ENamedThreads.h"
#include "UE/F/FGraphEvent.h"

namespace UE
{
	class FRenderCommandFence
	{
	public:
		// members
		mutable FGraphEventRef completionEvent;     // 00
		ENamedThreads          triggerThreadIndex;  // 08
	};
	static_assert(sizeof(FRenderCommandFence) == 0x10);
}
