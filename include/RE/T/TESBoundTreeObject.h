#pragma once

#include "RE/T/TESBoundObject.h"

namespace RE
{
	class BSTreeNode;

	class TESBoundTreeObject :
		public TESBoundObject
	{
	public:
		// add
		virtual void RefreshBound(BSTreeNode* a_node);  // 4D
	};
	static_assert(sizeof(TESBoundTreeObject) == 0x48);
}
