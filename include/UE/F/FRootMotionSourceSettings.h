#pragma once

namespace UE
{
	class FRootMotionSourceSettings
	{
	public:
		// members
		std::uint8_t flags; // 00
	};
	static_assert(sizeof(FRootMotionSourceSettings) == 0x1);
}
