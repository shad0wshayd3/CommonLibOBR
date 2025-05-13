#pragma once

namespace UE
{
	class FDelegateHandle
	{
	public:
		FDelegateHandle() = default;

		// members
		std::uint64_t id{ 0 };  // 000
	};
	static_assert(sizeof(FDelegateHandle) == 0x008);
}
