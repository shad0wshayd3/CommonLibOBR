#pragma once

#include "UE/E/ELegacyMapMenuPage.h"
#include "UE/F/FDelegateHandle.h"
#include "UE/F/FInputText.h"
#include "UE/F/FLegacyMapMenuQuestProperties.h"
#include "UE/F/FLegacyMapMenuTitleProperties.h"
#include "UE/F/FString.h"
#include "UE/T/TMap.h"
#include "UE/T/TObjectPtr.h"
#include "UE/U/UVViewModelBase.h"

namespace UE
{
	class UVMapPageViewModel;

	class UVMapMenuViewModel :
		public UVViewModelBase
	{
	public:
		UE_DEFINE_UOBJECT(UVMapMenuViewModel, UVViewModelBase, "Altar", "VMapMenuViewModel");

		// members
		FDelegateHandle                       pageUpdatedDelegateHandle;  // 0D0
		ELegacyMapMenuPage                    currentPage;                // 0D8
		FLegacyMapMenuTitleProperties         titleProperties;            // 0E0
		TArray<FLegacyMapMenuQuestProperties> quests;                     // 110
		TArray<FLegacyMapMenuQuestProperties> questHistory;               // 120
		FLegacyMapMenuQuestProperties         activeQuestData;            // 130
		TObjectPtr<UVMapPageViewModel>        localMapMenuViewModel;      // 1C8
		TObjectPtr<UVMapPageViewModel>        worldMapMenuViewModel;      // 1D0
		std::int32_t                          questIndex;                 // 1D8
		TMap<FString, FInputText>             iconSelectionMap;           // 1E0
	};
	static_assert(sizeof(UVMapMenuViewModel) == 0x230);
}
