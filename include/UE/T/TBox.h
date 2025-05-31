#pragma once

#include "UE/T/TVector.h"

namespace UE::Math
{
	template <class T>
	class TBox
	{
	public:
		// members
		TVector<T>   min;    // 000
		TVector<T>   max;    // 018
		std::uint8_t valid;  // 030
	};
	static_assert(sizeof(TBox<double>) == 0x38);
}
