#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESValueForm :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESValueForm;
		inline static constexpr auto VTABLE = VTABLE::TESValueForm;

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;                   // 00
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;     // 02
		virtual bool CompareComponent(BaseFormComponent* a_rhs) override;  // 03

		// add
		virtual std::uint16_t GetSaveSize(std::uint32_t a_flags);                             // 04
		virtual void          SaveGame(std::uint32_t a_flags);                                // 05
		virtual void          LoadGame(std::uint32_t a_flags, std::uint32_t a_currentFlags);  // 06

		// members
		std::uint32_t value;  // 08
	};
	static_assert(sizeof(TESValueForm) == 0x10);
}
