#pragma once

#include "RE/N/NiTDefaultAllocator.h"
#include "RE/N/NiTListItem.h"

namespace RE
{
	template <class Allocator, class T>
	class NiTListBase
	{
	public:
		struct AntiBloatAllocator
		{
		public:
			// members
			std::uint32_t count;  // 00
		};
		static_assert(sizeof(AntiBloatAllocator) == 0x04);

		// add
		virtual ~NiTListBase();                                   // 00
		virtual NiTListItem<T>* NewItem() = 0;                    // 01
		virtual void            DeleteItem(NiTListItem<T>*) = 0;  // 02

		// members
		NiTListItem<T>*                 head;       // 08
		NiTListItem<T>*                 tail;       // 10
		NiTListBase::AntiBloatAllocator allocator;  // 18
	};
	static_assert(sizeof(NiTListBase<NiTDefaultAllocator<void*>, void*>) == 0x20);
}
