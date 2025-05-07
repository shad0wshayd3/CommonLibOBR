#pragma once

#include "RE/T/TSetElementBase.h"

namespace RE::UE
{
	template <class T>
	class TSetElement :
		public TSetElementBase<T>
	{
	public:
	};
	static_assert(sizeof(TSetElement<void*>) == 0x10);
}
