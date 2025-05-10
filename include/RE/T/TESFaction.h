#pragma once

#include "RE/B/BSTList.h"
#include "RE/F/FACTION_DATA.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESReactionForm.h"

namespace RE
{
	struct RANK_DATA;

	class TESFaction :
		public TESForm,
		public TESFullName,
		public TESReactionForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESFaction;
		inline static constexpr auto VTABLE = VTABLE::TESFaction;
		inline static constexpr auto FORMTYPE = FormType::Faction;

		// members
		FACTION_DATA             data;           // 68
		float                    crimeGoldMult;  // 6C
		BSSimpleList<RANK_DATA*> rankData;       // 70
	};
	static_assert(sizeof(TESFaction) == 0x80);
}
