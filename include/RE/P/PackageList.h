#pragma once

#include "RE/B/BSTList.h"

namespace RE
{
	class TESPackage;

	struct PackageList
	{
	public:
		// members
		BSSimpleList<TESPackage*> packages;  // 00
	};
	static_assert(sizeof(PackageList) == 0x10);
}
