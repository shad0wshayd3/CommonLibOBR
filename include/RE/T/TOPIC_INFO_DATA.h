#pragma once

namespace RE
{
	struct TOPIC_INFO_DATA
	{
	public:
		// members
		std::uint8_t type;         // 00
		std::uint8_t nextSpeaker;  // 01
		std::uint8_t flags;        // 02
	};
	static_assert(sizeof(TOPIC_INFO_DATA) == 0x03);
}
