#pragma once

#include "RE/B/BSTList.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESMagicCasterForm.h"
#include "RE/T/TESMagicTargetForm.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESScriptableForm.h"

namespace RE
{
	class TESForm;
	class TESSound;

	class TESObjectDOOR :
		public TESBoundAnimObject,
		public TESFullName,
		public TESModel,
		public TESScriptableForm,
		public TESMagicCasterForm,
		public TESMagicTargetForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESObjectDOOR;
		inline static constexpr auto VTABLE = VTABLE::TESObjectDOOR;
		inline static constexpr auto FORMTYPE = FormType::Door;

		// override (TESForm)
		virtual ~TESObjectDOOR() override;                                                                                                                                       // 04
		virtual void         InitializeData() override;                                                                                                                          // 05
		virtual void         ClearData() override;                                                                                                                               // 06
		virtual bool         Load(TESFile* a_file) override;                                                                                                                     // 07
		virtual void         Save() override;                                                                                                                                    // 09
		virtual void         InitItem() override;                                                                                                                                // 1B
		virtual void         Copy(TESForm* a_srcForm) override;                                                                                                                  // 2D
		virtual bool         Compare(TESForm* a_copyForm) override;                                                                                                              // 2E
		virtual bool         Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, bool a_idFlag, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 33
		virtual NiAVObject** Clone3D(TESObjectREFR* a_ref) override;                                                                                                             // 4A

		// members
		std::byte              padA8[4];         // A8
		TESSound*              openSound;        // B0
		TESSound*              closeSound;       // B8
		TESSound*              loopSound;        // C0
		std::uint8_t           flags;            // C8
		BSSimpleList<TESForm*> randomTeleports;  // D0
	};
	// static_assert(sizeof(TESObjectDOOR) == 0xE0);
	static_assert(offsetof(TESObjectDOOR, openSound) == 0xB0);
	static_assert(offsetof(TESObjectDOOR, closeSound) == 0xB8);
	static_assert(offsetof(TESObjectDOOR, loopSound) == 0xC0);
	static_assert(offsetof(TESObjectDOOR, flags) == 0xC8);
	static_assert(offsetof(TESObjectDOOR, randomTeleports) == 0xD0);
}
