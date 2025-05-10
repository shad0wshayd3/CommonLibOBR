#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/M/MagicSystem.h"

namespace RE
{
	class EnchantmentItem;

	class TESEnchantableForm :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESEnchantableForm;
		inline static constexpr auto VTABLE = VTABLE::TESEnchantableForm;

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;                   // 00
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;     // 02
		virtual bool CompareComponent(BaseFormComponent* a_rhs) override;  // 03

		// add
		virtual MagicSystem::CastingType GetCastingType();  // 04

		// members
		EnchantmentItem*         formEnchanting;       // 08
		std::uint16_t            amountOfEnchantment;  // 10
		MagicSystem::CastingType castingType;          // 14
	};
	static_assert(sizeof(TESEnchantableForm) == 0x18);
}
