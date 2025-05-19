#pragma once

namespace RE
{
	class OBJ_BOOK
	{
	public:
		// members
		std::uint8_t flags;    // 00
		std::uint8_t teaches;  // 01
	};
	static_assert(sizeof(OBJ_BOOK) == 0x02);
}
