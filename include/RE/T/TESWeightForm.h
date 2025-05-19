#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESWeightForm :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESWeightForm;
		inline static constexpr auto VTABLE = VTABLE::TESWeightForm;

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;                   // 00
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;     // 02
		virtual bool CompareComponent(BaseFormComponent* a_rhs) override;  // 03

		// members
		float weight;  // 08
	};
	static_assert(sizeof(TESWeightForm) == 0x10);
}
