#pragma once

#include "RE/N/NiTDefaultAllocator.h"
#include "RE/N/NiTListBase.h"
#include "RE/N/NiTListItem.h"

namespace RE
{
	template <class Allocator, class T>
	class NiTPointerListBase :
		public NiTListBase<Allocator, T>
	{
	public:
		// override
		virtual ~NiTPointerListBase() override;                        // 00
		virtual NiTListItem<T>* NewItem() override;                    // 01
		virtual void            DeleteItem(NiTListItem<T>*) override;  // 02
	};
	static_assert(sizeof(NiTPointerListBase<NiTDefaultAllocator<void*>, void*>) == 0x20);
}
