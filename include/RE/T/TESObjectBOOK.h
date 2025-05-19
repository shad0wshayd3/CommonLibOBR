#pragma once

#include "RE/O/OBJ_BOOK.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESEnchantableForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESScriptableForm.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class TESObjectBOOK :
		public TESBoundObject,
		public TESFullName,
		public TESModel,
		public TESIcon,
		public TESScriptableForm,
		public TESEnchantableForm,
		public TESValueForm,
		public TESWeightForm,
		public TESDescription
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESObjectBOOK;
		inline static constexpr auto VTABLE = VTABLE::TESObjectBOOK;
		inline static constexpr auto FORMTYPE = FormType::Book;

		// override (TESForm)
		virtual ~TESObjectBOOK() override;                                                                                                                                         // 04
		virtual void           InitializeData() override;                                                                                                                          // 05
		virtual bool           Load(TESFile* a_file) override;                                                                                                                     // 07
		virtual void           Save() override;                                                                                                                                    // 09
		virtual std::uint16_t  GetSaveSize(std::uint32_t a_changeFlags) override;                                                                                                  // 13
		virtual void           SaveGame(std::uint32_t a_changeFlags) override;                                                                                                     // 14
		virtual void           LoadGame(std::uint32_t a_flags, std::uint32_t a_currentFlags) override;                                                                             // 15
		virtual void           InitItem() override;                                                                                                                                // 1B
		virtual void           Copy(TESForm* a_srcForm) override;                                                                                                                  // 2D
		virtual bool           Compare(TESForm* a_copyForm) override;                                                                                                              // 2E
		virtual bool           Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, bool a_idFlag, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 33
		virtual void           FillExportForm(bool a_gameplayOnly) override;                                                                                                       // 38
		virtual void           UpdateFormValues(const ExportTESForm* a_exportForm) override;                                                                                       // 39
		virtual ExportTESForm* GetExportForm(bool a_fullLoad) override;                                                                                                            // 3A

		// members
		OBJ_BOOK data;  // 108
	};
	static_assert(sizeof(TESObjectBOOK) == 0x110);
}
