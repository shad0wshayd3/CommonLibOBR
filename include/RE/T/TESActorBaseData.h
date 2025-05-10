#pragma once

#include "RE/A/ACTOR_BASE_DATA.h"
#include "RE/B/BSTList.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class FACTION_RANK;
	class TESLevItem;

	struct TESActorBaseData :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESActorBaseData;
		inline static constexpr auto VTABLE = VTABLE::TESActorBaseData;

		// members
		ACTOR_BASE_DATA             actorData;  // 08
		TESLevItem*                 deathItem;  // 18
		BSSimpleList<FACTION_RANK*> factions;   // 20
	};
	static_assert(sizeof(TESActorBaseData) == 0x30);
}
