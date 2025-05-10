#pragma once

#include "RE/O/OBJ_ARMO.h"
#include "RE/T/TESBipedModelForm.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESEnchantableForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESHealthForm.h"
#include "RE/T/TESScriptableForm.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class TESObjectARMO :
		public TESBoundObject,
		public TESFullName,
		public TESScriptableForm,
		public TESEnchantableForm,
		public TESValueForm,
		public TESWeightForm,
		public TESHealthForm,
		public TESBipedModelForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESObjectARMO;
		inline static constexpr auto VTABLE = VTABLE::TESObjectARMO;
		inline static constexpr auto FORMTYPE = FormType::Armor;

		// override (TESForm)
		virtual ~TESObjectARMO() override;                                                              // 04
		virtual void           InitializeData() override;                                               // 05
		virtual bool           Load(TESFile* a_file) override;                                          // 07
		virtual void           Save() override;                                                         // 09
		virtual void           LoadGame(std::uint32_t a_flags, std::uint32_t a_currentFlags) override;  // 15
		virtual void           InitItem() override;                                                     // 1B
		virtual void           Copy(TESForm* a_srcForm) override;                                       // 2D
		virtual bool           Compare(TESForm* a_copyForm) override;                                   // 2E
		virtual void           FillExportForm(bool a_gameplayOnly) override;                            // 38
		virtual void           UpdateFormValues(const ExportTESForm* a_exportForm) override;            // 39
		virtual ExportTESForm* GetExportForm(bool a_fullLoad) override;                                 // 3A
		virtual bool           HasDifferentFormValues(const ExportTESForm* a_exportForm) override;      // 3B

		// members
		OBJ_ARMO data;  // 1C0
	};
	static_assert(sizeof(TESObjectARMO) == 0x1C8);
}
