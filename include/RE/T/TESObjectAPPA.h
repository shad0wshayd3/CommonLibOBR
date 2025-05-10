#pragma once

#include "RE/O/OBJ_APPA.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESQualityForm.h"
#include "RE/T/TESScriptableForm.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class TESObjectAPPA :
		public TESBoundObject,
		public TESFullName,
		public TESModel,
		public TESIcon,
		public TESScriptableForm,
		public TESValueForm,
		public TESWeightForm,
		public TESQualityForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESObjectAPPA;
		inline static constexpr auto VTABLE = VTABLE::TESObjectAPPA;
		inline static constexpr auto FORMTYPE = FormType::Apparatus;

		// override (TESForm)
		virtual ~TESObjectAPPA() override;                   // 04
		virtual void InitializeData() override;              // 05
		virtual bool Load(TESFile* a_file) override;         // 07
		virtual void Save() override;                        // 09
		virtual void InitItem() override;                    // 1B
		virtual void Copy(TESForm* a_srcForm) override;      // 2D
		virtual bool Compare(TESForm* a_copyForm) override;  // 2E

		// members
		OBJ_APPA data;  // F0
	};
	static_assert(sizeof(TESObjectAPPA) == 0xF8);
}
