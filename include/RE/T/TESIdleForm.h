#pragma once

#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModelAnim.h"

namespace RE
{
	class NiFormArray;

	class TESIdleForm :
		public TESForm,
		public TESModelAnim
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESIdleForm;
		inline static constexpr auto VTABLE = VTABLE::TESIdleForm;
		inline static constexpr auto FORMTYPE = FormType::Idle;

		// members
		TESCondition conditions;  // 60
		std::uint8_t animData;    // 70
		NiFormArray* childIdles;  // 78
		TESIdleForm* parentIdle;  // 80
		TESIdleForm* prevIdle;    // 88
	};
	static_assert(sizeof(TESIdleForm) == 0x90);
}
