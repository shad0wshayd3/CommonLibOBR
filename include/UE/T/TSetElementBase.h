#pragma once

#include "UE/F/FSetElementId.h"

namespace UE
{
	template <class T, std::size_t N = 1>
	class TSetElementBase
	{
	public:
		// members
		T             value;       // 00
		FSetElementId hashNextId;  // ??
		std::int32_t  hashIndex;   // ??
	};
	static_assert(sizeof(TSetElementBase<void*, 1>) == 0x10);
}
