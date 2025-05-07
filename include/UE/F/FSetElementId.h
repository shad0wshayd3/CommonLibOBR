#pragma once

namespace UE
{
	class FSetElementId
	{
	public:
		// members
		std::int32_t index;  // 00
	};
	static_assert(sizeof(FSetElementId) == 0x04);
}
