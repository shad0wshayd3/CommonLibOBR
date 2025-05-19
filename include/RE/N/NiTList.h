#pragma once

#include "RE/N/NiTDefaultAllocator.h"
#include "RE/N/NiTPointerListBase.h"

namespace RE
{
	template <class T>
	class NiTList :
		public NiTPointerListBase<NiTDefaultAllocator<T>, T>
	{
	public:
		// override
		virtual ~NiTList() override;  // 00
	};
	static_assert(sizeof(NiTList<void*>) == 0x20);
}
