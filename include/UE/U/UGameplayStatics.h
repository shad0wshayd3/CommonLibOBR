#pragma once

#include "UE/U/UBlueprintFunctionLibrary.h"

namespace UE
{
	class APlayerController;
	class UObject;

	class UGameplayStatics :
		public UBlueprintFunctionLibrary
	{
	public:
		UE_DEFINE_UOBJECT("Engine", "GameplayStatics");

		// override
		virtual ~UGameplayStatics();  // 00

		static APlayerController* GetPlayerController(const UObject* a_worldContextObject, std::int32_t a_playerIndex)
		{
			using func_t = decltype(&UGameplayStatics::GetPlayerController);
			static REL::Relocation<func_t> func{ ID::UGameplayStatics::GetPlayerController };
			return func(a_worldContextObject, a_playerIndex);
		}
	};
	static_assert(sizeof(UGameplayStatics) == 0x28);
}
