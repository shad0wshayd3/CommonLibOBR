#pragma once

namespace RE
{
	class OBJ_APPA
	{
	public:
		// members
		std::uint8_t type;  // 00
	};
	static_assert(sizeof(OBJ_APPA) == 0x01);
}
