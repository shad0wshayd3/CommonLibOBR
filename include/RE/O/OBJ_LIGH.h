#pragma once

namespace RE
{
	struct OBJ_LIGH
	{
	public:
		// members
		std::int32_t  time;             // 00
		std::uint32_t radius;           // 04
		std::uint32_t color;            // 08
		std::uint32_t flags;            // 0C
		float         fallOffExponent;  // 10
		float         fov;              // 14
	};
	static_assert(sizeof(OBJ_LIGH) == 0x18);
}
