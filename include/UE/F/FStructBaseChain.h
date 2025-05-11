#pragma once

namespace UE
{
	class FStructBaseChain
	{
	public:
		bool IsChildOfUsingStructArray(const FStructBaseChain& a_parent) const
		{
			std::int32_t num = a_parent.numStructBasesInChainMinusOne;
			return num <= numStructBasesInChainMinusOne && structBaseChainArray[num] == &a_parent;
		}

		// members
		FStructBaseChain** structBaseChainArray;           // 00
		std::int32_t       numStructBasesInChainMinusOne;  // 08
	};
	static_assert(sizeof(FStructBaseChain) == 0x10);
}
