#pragma once

#include "RE/B/BSStringT.h"
#include "RE/B/BSTList.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	struct LOAD_FORM_DATA;

	class TESLoadScreen :
		public TESForm,
		public TESTexture,
		public TESDescription
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESLoadScreen;
		inline static constexpr auto VTABLE = VTABLE::TESLoadScreen;
		inline static constexpr auto FORMTYPE = FormType::LoadScreen;

		// members
		BSSimpleList<LOAD_FORM_DATA*> loadFormList;     // 58
		BSString                      descriptionText;  // 68
	};
	static_assert(sizeof(TESLoadScreen) == 0x78);
}
