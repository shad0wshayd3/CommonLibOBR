#pragma once

namespace RE
{
	struct NPC_DATA
	{
	public:
		// members
		std::uint8_t skill[21];  // 00
	};
	static_assert(sizeof(NPC_DATA) == 0x15);
}
