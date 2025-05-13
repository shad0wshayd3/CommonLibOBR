#pragma once

#include "UE/T/TSetAllocator.h"

namespace UE
{
	class FDefaultSetAllocator :
		public TSetAllocator<>
	{
	public:
	};
	static_assert(std::is_empty_v<FDefaultSetAllocator>);
}
