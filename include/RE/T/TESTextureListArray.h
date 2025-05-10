#pragma once

namespace RE
{
	class TESTextureList;

	struct TESTextureListArray
	{
	public:
		// members
		std::uint32_t    textureListCount;  // 00
		TESTextureList** textureLists;      // 08
	};
	static_assert(sizeof(TESTextureListArray) == 0x10);
}
