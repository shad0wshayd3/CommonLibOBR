#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESRace;

	struct TESRaceForm :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESRaceForm;
		inline static constexpr auto VTABLE = VTABLE::TESRaceForm;

		// members
		TESRace* formRace;  // 08
	};
	static_assert(sizeof(TESRaceForm) == 0x10);
}
