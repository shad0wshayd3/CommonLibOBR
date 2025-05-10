#pragma once

namespace RE
{
	struct DIALOGUE_DATA
	{
	public:
		// members
		std::uint8_t type;  // 00
	};
	static_assert(sizeof(DIALOGUE_DATA) == 0x01);
}
