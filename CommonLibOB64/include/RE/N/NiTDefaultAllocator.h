#pragma once

#include "RE/M/MemoryManager.h"

#define NiTDefaultAllocator DFALL

namespace RE
{
	template <class T>
	class NiTDefaultAllocator
	{
	public:
		void* Allocate()
		{
			return malloc(sizeof(T));
		}

		void Deallocate(void* a_ptr)
		{
			return free(a_ptr);
		}
	};
}
