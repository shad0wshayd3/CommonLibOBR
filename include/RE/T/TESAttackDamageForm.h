#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESAttackDamageForm :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESAttackDamageForm;
		inline static constexpr auto VTABLE = VTABLE::TESAttackDamageForm;

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;                   // 00
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;     // 02
		virtual bool CompareComponent(BaseFormComponent* a_rhs) override;  // 03

		// add
		virtual std::uint16_t GetAttackDamage();  // 04

		// members
		std ::uint16_t attackDamage;  // 08
	};
	static_assert(sizeof(TESAttackDamageForm) == 0x10);
}
