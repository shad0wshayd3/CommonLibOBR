#pragma once

namespace RE
{
	struct BIPED_MODEL
	{
	public:
		// members
		std::uint16_t bipedObjectSlots;  // 00
		std::uint8_t  flags;             // 02
	};
	static_assert(sizeof(BIPED_MODEL) == 0x04);
}
