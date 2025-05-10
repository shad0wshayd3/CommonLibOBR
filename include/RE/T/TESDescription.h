#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/C/CHUNK_ID.h"

namespace RE
{
	class TESForm;

	class TESDescription :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESDescription;
		inline static constexpr auto VTABLE = VTABLE::TESDescription;

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;                   // 00
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;     // 02
		virtual bool CompareComponent(BaseFormComponent* a_rhs) override;  // 03

		// add
		virtual const char* GetDescription(TESForm* a_form, CHUNK_ID a_chunk);  // 04

		// members
		std::uint32_t fileOffset;  // 08
	};
	static_assert(sizeof(TESDescription) == 0x10);
}
