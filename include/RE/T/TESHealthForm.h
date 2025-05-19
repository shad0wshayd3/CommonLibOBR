#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESHealthForm :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESHealthForm;
		inline static constexpr auto VTABLE = VTABLE::TESHealthForm;

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;                   // 00
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;     // 02
		virtual bool CompareComponent(BaseFormComponent* a_rhs) override;  // 03

		// add
		std::uint32_t GetFormHealth();  // 04

		// members
		std::uint32_t health;  // 08
	};
	static_assert(sizeof(TESHealthForm) == 0x10);
}
