#pragma once

namespace UE
{
	template <std::size_t N, std::size_t O>
	class TAllocatorFixedSizeFreeList
	{
	public:
		class FreeListNode
		{
		public:
			// members
			FreeListNode* nextFreeAllocation;  // 00
		};

		static_assert(sizeof(FreeListNode) == 0x08);

		// members
		FreeListNode* freeList;      // 00
		std::uint32_t numAllocated;  // 08
		std::uint32_t numLive;       // 0C
	};
	static_assert(sizeof(TAllocatorFixedSizeFreeList<24, 256>) == 0x10);
}
