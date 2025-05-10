#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESQualityForm :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESQualityForm;
		inline static constexpr auto VTABLE = VTABLE::TESQualityForm;

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;                   // 00
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;     // 02
		virtual bool CompareComponent(BaseFormComponent* a_rhs) override;  // 03

		// members
		float quality;  // 08
	};
	static_assert(sizeof(TESQualityForm) == 0x10);
}
