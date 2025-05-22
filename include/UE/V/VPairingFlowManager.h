#pragma once

#include "UE/F/FCriticalSection.h"
#include "UE/T/TMap.h"
#include "UE/T/TSharedPtr.h"

namespace UE
{
	class VAsyncBuffersPool;
	class VBasePairingFlow;
	class VForwardPairingFlow;
	class VReversePairingFlow;

	class VPairingFlowManager
	{
	public:
		TMap<std::uint32_t, VBasePairingFlow*> buffers;               // 00
		VForwardPairingFlow*                   forwardFlow;           // 50
		VReversePairingFlow*                   reverseFlow;           // 58
		VBasePairingFlow*                      currentFlowOriginal;   // 60
		VBasePairingFlow*                      currentFlowHost;       // 68
		FWindowsCriticalSection                mapAccessLock;         // 70
		TSharedPtr<VAsyncBuffersPool>          asyncBuffersPool;      // 98
		std::uint32_t                          gameThreadId;          // A8
		std::uint32_t                          originalGameThreadId;  // AC
	};
	static_assert(sizeof(VPairingFlowManager) == 0xB0);
}
