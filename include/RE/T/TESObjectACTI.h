#pragma once

#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESMagicTargetForm.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESScriptableForm.h"

namespace RE
{
	class TESSound;

	class TESObjectACTI :
		public TESBoundAnimObject,
		public TESFullName,
		public TESModel,
		public TESScriptableForm,
		public TESMagicTargetForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESObjectACTI;
		inline static constexpr auto VTABLE = VTABLE::TESObjectACTI;
		inline static constexpr auto FORMTYPE = FormType::Activator;

		// override (TESForm)
		virtual ~TESObjectACTI() override;                                                                                                                               // 04
		virtual void InitializeData() override;                                                                                                                          // 05
		virtual bool Load(TESFile* a_file) override;                                                                                                                     // 07
		virtual void Save() override;                                                                                                                                    // 09
		virtual void InitItem() override;                                                                                                                                // 1B
		virtual void Copy(TESForm* a_srcForm) override;                                                                                                                  // 2D
		virtual bool Compare(TESForm* a_copyForm) override;                                                                                                              // 2E
		virtual bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, bool a_idFlag, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 33

		// members
		TESSound* soundLoop;  // A8
	};
	static_assert(sizeof(TESObjectACTI) == 0xB0);
}
