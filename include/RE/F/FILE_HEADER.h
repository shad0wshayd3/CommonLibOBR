#pragma once

namespace RE
{
	struct FILE_HEADER
	{
	public:
		// members
		float         version;     // 00
		std::uint32_t formCount;   // 04
		std::uint32_t nextFormID;  // 08
	};
	static_assert(sizeof(FILE_HEADER) == 0xC);
}
