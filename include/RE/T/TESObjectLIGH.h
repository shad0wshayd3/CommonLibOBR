#pragma once

#include "RE/O/OBJ_LIGH.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESScriptableForm.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class TESSound;

	class TESObjectLIGH :
		public TESBoundAnimObject,
		public TESFullName,
		public TESModel,
		public TESIcon,
		public TESScriptableForm,
		public TESWeightForm,
		public TESValueForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESObjectLIGH;
		inline static constexpr auto VTABLE = VTABLE::TESObjectLIGH;
		inline static constexpr auto FORMTYPE = FormType::Light;

		// override (TESForm)
		virtual ~TESObjectLIGH() override;                                                                                                                                        // 04
		virtual void          InitializeData() override;                                                                                                                          // 05
		virtual bool          Load(TESFile* a_file) override;                                                                                                                     // 07
		virtual void          Save() override;                                                                                                                                    // 09
		virtual std::uint16_t GetSaveSize(std::uint32_t a_changeFlags) override;                                                                                                  // 13
		virtual void          SaveGame(std::uint32_t a_changeFlags) override;                                                                                                     // 14
		virtual void          LoadGame(std::uint32_t a_flags, std::uint32_t a_currentFlags) override;                                                                             // 15
		virtual void          InitItem() override;                                                                                                                                // 1B
		virtual void          Copy(TESForm* a_srcForm) override;                                                                                                                  // 2D
		virtual bool          Compare(TESForm* a_copyForm) override;                                                                                                              // 2E
		virtual bool          Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, bool a_idFlag, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 33
		virtual void          UnClone3D(TESObjectREFR* a_ref) override;                                                                                                           // 41
		virtual NiAVObject*   LoadGraphics(TESObjectREFR* a_ref) override;                                                                                                        // 49
		virtual NiAVObject**  Clone3D(TESObjectREFR* a_ref) override;                                                                                                             // 4A

		// members
		OBJ_LIGH  data;   // 0E0
		float     fade;   // 0F8
		TESSound* sound;  // 100
	};
	static_assert(sizeof(TESObjectLIGH) == 0x108);
}
