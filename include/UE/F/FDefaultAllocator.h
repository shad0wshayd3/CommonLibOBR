#pragma once

#include "UE/T/TSizedDefaultAllocator.h"

namespace UE
{
	using FDefaultAllocator = TSizedDefaultAllocator<32>;
	using FDefaultAllocator64 = TSizedDefaultAllocator<64>;
}
