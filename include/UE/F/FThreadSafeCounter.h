#pragma once

namespace UE
{
	class FThreadSafeCounter
	{
	public:
		// members
		volatile std::int32_t counter;
	};
	static_assert(sizeof(FThreadSafeCounter) == 0x04);
}
