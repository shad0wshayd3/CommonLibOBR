#pragma once

namespace UE
{
	class UObject;

	class VPairingEntry
	{
	public:
		// members
		void*                      originalItem;            // 00
		UObject*                   hostItem;                // 08
		bool                       isPaired;                // 10
		bool                       readyBeDestroyed;        // 11
		bool                       skipHandlers;            // 12
		bool                       isHostItemSpawnPending;  // 13
		std::atomic<std::uint32_t> referenceCount;          // 14
	};
	static_assert(sizeof(VPairingEntry) == 0x18);
}
