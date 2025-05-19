#pragma once

namespace RE
{
	template <class T>
	class NiTListItem
	{
	public:
		// members
		NiTListItem<T>* next;     // 00
		NiTListItem<T>* prev;     // 08
		T               element;  // 10
	};
	static_assert(sizeof(NiTListItem<void*>) == 0x18);
}
