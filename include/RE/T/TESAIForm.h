#pragma once

#include "RE/A/AIDATA.h"
#include "RE/B/BaseFormComponent.h"
#include "RE/P/PackageList.h"

namespace RE
{
	struct TESAIForm :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESAIForm;
		inline static constexpr auto VTABLE = VTABLE::TESAIForm;

		// members
		AIDATA      aiData;      // 08
		PackageList aiPackList;  // 18
	};
	static_assert(sizeof(TESAIForm) == 0x28);
}
