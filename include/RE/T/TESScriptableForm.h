#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class Script;

	class TESScriptableForm :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESScriptableForm;
		inline static constexpr auto VTABLE = VTABLE::TESScriptableForm;

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;                   // 00
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;     // 02
		virtual bool CompareComponent(BaseFormComponent* a_rhs) override;  // 03

		// members
		Script* formScript;     // 08
		bool    isInitialized;  // 10
	};
	static_assert(sizeof(TESScriptableForm) == 0x18);
}
