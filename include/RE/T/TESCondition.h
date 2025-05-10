#pragma once

#include "RE/B/BSTList.h"

namespace RE
{
	class TESConditionItem;

	struct TESCondition
	{
	public:
		// members
		BSSimpleList<TESConditionItem*> conditions;  // 00
	};
	static_assert(sizeof(TESCondition) == 0x10);
}
