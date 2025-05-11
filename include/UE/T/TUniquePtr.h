#pragma once

#include "UE/T/TDefaultDelete.h"

namespace UE
{
	template <class T, class D = TDefaultDelete<T>>
	class TUniquePtr :
		private D
	{
	public:
		T* ptr;
	};
}
