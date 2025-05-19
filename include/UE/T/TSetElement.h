#pragma once

#include "UE/T/TSetElementBase.h"

namespace UE
{
	template <class T>
	class TSetElement :
		public TSetElementBase<T>
	{
	public:
	};
	static_assert(sizeof(TSetElement<void*>) == 0x10);
}
