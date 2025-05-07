#pragma once

#include "UE/S/SharedPointerInternals.h"

namespace UE
{
	class UObject;

	template <class T, std::size_t N = 1>
	class TSharedPtr
	{
	public:
		// members
		T*                                           object;                // 00
		SharedPointerInternals::FSharedReferencer<N> sharedReferenceCount;  // 08
	};
	static_assert(sizeof(TSharedPtr<void*>) == 0x10);
}
