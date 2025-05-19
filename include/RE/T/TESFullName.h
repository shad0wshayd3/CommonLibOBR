#pragma once

#include "RE/B/BSStringT.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESFullName :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESFullName;
		inline static constexpr auto VTABLE = VTABLE::TESFullName;

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;                   // 00
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;     // 02
		virtual bool CompareComponent(BaseFormComponent* a_rhs) override;  // 03

		// members
		BSString fullName;  // 08
	};
	static_assert(sizeof(TESFullName) == 0x18);
}
