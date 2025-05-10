#pragma once

namespace RE
{
	class OBJ_ARMO
	{
	public:
		// members
		std::uint16_t rating;  // 00
	};
	static_assert(sizeof(OBJ_ARMO) == 0x02);
}
