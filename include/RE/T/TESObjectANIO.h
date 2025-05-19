#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class TESIdleForm;

	class TESObjectANIO :
		public TESForm,
		public TESModel
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESObjectANIO;
		inline static constexpr auto VTABLE = VTABLE::TESObjectANIO;
		inline static constexpr auto FORMTYPE = FormType::AnimatedObject;

		// override (TESForm)
		virtual ~TESObjectANIO() override;                   // 04
		virtual bool Load(TESFile* a_file) override;         // 07
		virtual void Save() override;                        // 09
		virtual void InitItem() override;                    // 1B
		virtual void Copy(TESForm* a_srcForm) override;      // 2D
		virtual bool Compare(TESForm* a_copyForm) override;  // 2E

		// members
		TESIdleForm* idleAnim;  // 60
	};
	static_assert(sizeof(TESObjectANIO) == 0x68);
}
