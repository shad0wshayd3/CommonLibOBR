#pragma once

namespace UE
{
	class FTimerHandle
	{
	public:
		FTimerHandle() = default;

		// members
		std::uint64_t handle{ 0 };
	};
	static_assert(sizeof(FTimerHandle) == 0x08);
}
