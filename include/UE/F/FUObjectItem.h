#pragma once

namespace UE
{
	class UObjectBase;

	class FUObjectItem
	{
	public:
		// members
		UObjectBase* object;            // 00
		std::int32_t flags;             // 08
		std::int32_t clusterRootIndex;  // 0C
		std::int32_t serialNumber;      // 10
	};
	static_assert(sizeof(FUObjectItem) == 0x18);
}
