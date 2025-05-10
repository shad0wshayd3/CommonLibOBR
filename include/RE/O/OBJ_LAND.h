#pragma once

namespace RE
{
	struct OBJ_LAND
	{
	public:
		// members
		std::uint32_t flags;  // 00
	};
	static_assert(sizeof(OBJ_LAND) == 0x04);
}
