#pragma once

namespace UE
{
	class FStructBaseChain
	{
	public:
		// members
		FStructBaseChain** structBaseChainArray;           // 00
		std::int32_t       numStructBasesInChainMinusOne;  // 08
	};
	static_assert(sizeof(FStructBaseChain) == 0x10);
}
