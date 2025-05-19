#pragma once

#include "RE/T/TESBoundObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESScriptableForm.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class TESObjectMISC :
		public TESBoundObject,
		public TESFullName,
		public TESModel,
		public TESIcon,
		public TESScriptableForm,
		public TESValueForm,
		public TESWeightForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESObjectMISC;
		inline static constexpr auto VTABLE = VTABLE::TESObjectMISC;
		inline static constexpr auto FORMTYPE = FormType::Misc;

		// override (TESForm)
		virtual ~TESObjectMISC() override;                                        // 04
		virtual bool          Load(TESFile* a_file) override;                     // 07
		virtual void          Save() override;                                    // 09
		virtual std::uint16_t GetSaveSize(std::uint32_t a_changeFlags) override;  // 13
		virtual void          Copy(TESForm* a_srcForm) override;                  // 2D
		virtual bool          Compare(TESForm* a_copyForm) override;              // 2E
	};
	static_assert(sizeof(TESObjectMISC) == 0xE0);
}
