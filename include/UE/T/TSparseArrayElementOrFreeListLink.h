#pragma once

namespace UE
{
	template <class T>
	class TSparseArrayElementOrFreeListLink
	{
	public:
		// members
		T elementData;  // 00
		union
		{
			std::int32_t prevFreeIndex;
			std::int32_t nextFreeIndex;
		};
	};
	static_assert(sizeof(TSparseArrayElementOrFreeListLink<void*>) == 0x10);
}
