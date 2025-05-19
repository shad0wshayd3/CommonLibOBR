#pragma once

#include "UE/F/FSparseDelegate.h"

namespace UE
{
	template <class TM, class TC, class TI>
	class TSparseDynamicDelegate :
		public FSparseDelegate
	{
	public:
	};
	static_assert(sizeof(TSparseDynamicDelegate<void, void, void>) == 0x01);
}
