#pragma once

#include "UE/F/FGuid.h"
#include "UE/F/FName.h"
#include "UE/T/TMap.h"
#include "UE/U/UMVVMViewModelBase.h"

namespace UE
{
	class UPostTickExecutorSubsystem;
	class VPairingEntry;

	class UVViewModelBase :
		public UMVVMViewModelBase
	{
	public:
		UE_DEFINE_UOBJECT(UVViewModelBase, UMVVMViewModelBase, "/Script/Altar", "VViewModelBase");

		// members
		bool                                       isMenuOpen;           // 68
		VPairingEntry*                             pairingEntry;         // 70
		TMap<FName, FGuid>                         postTickEventsIDMap;  // 78
		TWeakObjectPtr<UPostTickExecutorSubsystem> postTickSubSystem;    // C8
	};
	static_assert(sizeof(UVViewModelBase) == 0xD0);
}
