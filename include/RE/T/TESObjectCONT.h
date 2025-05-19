#pragma once

#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESContainer.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESMagicCasterForm.h"
#include "RE/T/TESMagicTargetForm.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESScriptableForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class TESSound;

	class TESObjectCONT :
		public TESBoundAnimObject,
		public TESContainer,
		public TESFullName,
		public TESModel,
		public TESScriptableForm,
		public TESWeightForm,
		public TESMagicCasterForm,
		public TESMagicTargetForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESObjectCONT;
		inline static constexpr auto VTABLE = VTABLE::TESObjectCONT;
		inline static constexpr auto FORMTYPE = FormType::Container;

		// override (TESForm)
		virtual ~TESObjectCONT() override;                                                                                                                               // 04
		virtual void InitializeData() override;                                                                                                                          // 05
		virtual bool Load(TESFile* a_file) override;                                                                                                                     // 07
		virtual void Save() override;                                                                                                                                    // 09
		virtual void InitItem() override;                                                                                                                                // 1B
		virtual void Copy(TESForm* a_srcForm) override;                                                                                                                  // 2D
		virtual bool Compare(TESForm* a_copyForm) override;                                                                                                              // 2E
		virtual bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, bool a_idFlag, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 33

		// members
		std::byte    padD8[4];        // D8
		TESSound*    openSound;       // E0
		TESSound*    closeSound;      // E8
		std::uint8_t containerFlags;  // F0
	};
	// static_assert(sizeof(TESObjectCONT) == 0xF8);
	static_assert(offsetof(TESObjectCONT, openSound) == 0xE0);
	static_assert(offsetof(TESObjectCONT, closeSound) == 0xE8);
	static_assert(offsetof(TESObjectCONT, containerFlags) == 0xF0);
}
