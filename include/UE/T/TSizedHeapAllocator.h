#pragma once

namespace UE
{
	class FMemory;
	class FScriptContainerElement;

	template <std::size_t N, class Memory>
	class TSizedHeapAllocator
	{
	public:
		class ForAnyElementType
		{
		public:
			// members
			FScriptContainerElement* data;  // 00
		};
		static_assert(sizeof(ForAnyElementType) == 0x08);

		template <class T>
		class ForElementType :
			public ForAnyElementType
		{
		public:
		};
		static_assert(sizeof(ForElementType<void*>) == 0x08);
	};
	static_assert(std::is_empty_v<TSizedHeapAllocator<32, FMemory>>);
}
