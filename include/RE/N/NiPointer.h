#pragma once

namespace RE
{
	template <class T>
	class NiPointer
	{
	public:
		// members
		T* object;  // 00
	};
	static_assert(sizeof(NiPointer<void>) == 0x08);
}
