#pragma once

namespace RE
{
	struct PACKAGE_DATA
	{
	public:
		// members
		std::uint32_t packFlags;  // 00
		std::uint8_t  packType;   // 04
	};
	static_assert(sizeof(PACKAGE_DATA) == 0x08);
}
