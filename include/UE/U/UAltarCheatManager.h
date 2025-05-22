#pragma once

#include "UE/U/UCheatManager.h"

namespace UE
{
	class UUserWidget;

	class UAltarCheatManager :
		public UCheatManager
	{
	public:
		UE_DEFINE_UOBJECT(UAltarCheatManager, UCheatManager, "Altar", "AltarCheatManager");

		// override
		virtual ~UAltarCheatManager();  // 00

		AActor* GetSelectedActor()
		{
			using func_t = decltype(&UAltarCheatManager::GetSelectedActor);
			static REL::Relocation<func_t> func{ ID::UAltarCheatManager::GetSelectedActor };
			return func(this);
		}

		void SetSelectedActor(AActor* a_actor)
		{
			using func_t = decltype(&UAltarCheatManager::SetSelectedActor);
			static REL::Relocation<func_t> func{ ID::UAltarCheatManager::SetSelectedActor };
			return func(this, a_actor);
		}

		// members
		TWeakObjectPtr<AActor>   selectedActor;               // 088
		TSubclassOf<UUserWidget> graphicsDebugWidget;         // 090
		bool                     isGraphicsDebugWidgetShown;  // 098
		bool                     allowSetStage;               // 09C
	};
	static_assert(sizeof(UAltarCheatManager) == 0xA0);
}
