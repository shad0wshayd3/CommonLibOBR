#pragma once

#include "UE/F/FFieldPath.h"

namespace UE
{
	template <class T>
	class TFieldPath :
		public FFieldPath
	{
	public:
	};
	static_assert(sizeof(TFieldPath<FField>) == 0x20);
}
