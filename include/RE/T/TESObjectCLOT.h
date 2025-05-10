#pragma once

#include "RE/T/TESBipedModelForm.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESEnchantableForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESScriptableForm.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class TESObjectCLOT :
		public TESBoundObject,
		public TESFullName,
		public TESScriptableForm,
		public TESEnchantableForm,
		public TESValueForm,
		public TESWeightForm,
		public TESBipedModelForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESObjectCLOT;
		inline static constexpr auto VTABLE = VTABLE::TESObjectCLOT;
		inline static constexpr auto FORMTYPE = FormType::Clothing;

		// override (TESForm)
		virtual ~TESObjectCLOT() override;                                                    // 04
		virtual void           InitializeData() override;                                     // 05
		virtual bool           Load(TESFile* a_file) override;                                // 07
		virtual void           Save() override;                                               // 09
		virtual std::uint16_t  GetSaveSize(std::uint32_t a_changeFlags) override;             // 13
		virtual void           SaveGame(std::uint32_t a_changeFlags) override;                // 14
		virtual void           InitItem() override;                                           // 1B
		virtual void           Copy(TESForm* a_srcForm) override;                             // 2D
		virtual bool           Compare(TESForm* a_copyForm) override;                         // 2E
		virtual void           FillExportForm(bool a_gameplayOnly) override;                  // 38
		virtual void           UpdateFormValues(const ExportTESForm* a_exportForm) override;  // 39
		virtual ExportTESForm* GetExportForm(bool a_fullLoad) override;                       // 3A
	};
	static_assert(sizeof(TESObjectCLOT) == 0x1B0);
}
