#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	template <class T>
	class NiTPointerAllocator
	{
	public:
		class AllocNode
		{
		public:
			AllocNode* next;     // 00
			void*      data;     // 08
			T          element;  // 10
		};

		void* Allocate()
		{
			return malloc(sizeof(AllocNode));
		}

		void Deallocate(void* a_ptr)
		{
			return free(a_ptr);
		}
	};
}
