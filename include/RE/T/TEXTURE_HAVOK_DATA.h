#pragma once

namespace RE
{
	struct TEXTURE_HAVOK_DATA
	{
	public:
		// members
		std::uint8_t materialType;  // 00
		std::uint8_t friction;      // 01
		std::uint8_t restitution;   // 02
	};
	static_assert(sizeof(TEXTURE_HAVOK_DATA) == 0x03);
}
