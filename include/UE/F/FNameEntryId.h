#pragma once

namespace UE
{
	class FNameEntryId
	{
	public:
		// members
		std::uint32_t value;  // 00
	};
	static_assert(sizeof(FNameEntryId) == 0x04);
}
