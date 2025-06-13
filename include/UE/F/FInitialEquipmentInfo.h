#pragma once

namespace UE
{
	class UTESForm;

	class FInitialEquipmentInfo
	{
	public:
		// members
		UTESForm* equipmentForm;  // 000
		bool      useNPCDefault;  // 008
	};
	static_assert(sizeof(FInitialEquipmentInfo) == 0x10);
}
