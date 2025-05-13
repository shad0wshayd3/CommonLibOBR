#pragma once

namespace UE
{
	template <class T>
	union TSparseArrayElementOrFreeListLink
	{
	public:
		// members
		T elementData;  // 00
		struct
		{
			std::int32_t prevFreeIndex;
			std::int32_t nextFreeIndex;
		};
	};
	static_assert(sizeof(TSparseArrayElementOrFreeListLink<TAlignedBytes<16, 4>>) == 0x10);
}
