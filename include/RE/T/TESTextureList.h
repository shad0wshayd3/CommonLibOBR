#pragma once

namespace RE
{
	class BSFileEntry;

	class TESTextureList
	{
	public:
		// members
		std::uint8_t  textureCount;        // 00
		BSFileEntry** textureOffsetArray;  // 08
	};
	static_assert(sizeof(TESTextureList) == 0x10);
}
