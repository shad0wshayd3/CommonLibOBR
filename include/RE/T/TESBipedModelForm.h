#pragma once

#include "RE/B/BIPED_MODEL.h"
#include "RE/B/BaseFormComponent.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class TESBipedModelForm :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESBipedModelForm;
		inline static constexpr auto VTABLE = VTABLE::TESBipedModelForm;

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;                   // 00
		virtual void ClearDataComponent() override;                        // 01
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;     // 02
		virtual bool CompareComponent(BaseFormComponent* a_rhs) override;  // 03

		// members
		BIPED_MODEL bipedModelData;    // 08
		TESModel    bipedModel[2];     // 10
		TESModel    worldModel[2];     // 70
		TESIcon     inventoryIcon[2];  // D0
	};
	static_assert(sizeof(TESBipedModelForm) == 0x100);
}
