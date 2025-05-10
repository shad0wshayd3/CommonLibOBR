#pragma once

#include "RE/C/CLASS_DATA.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class TESClass :
		public TESForm,
		public TESFullName,
		public TESDescription,
		public TESTexture
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESClass;
		inline static constexpr auto VTABLE = VTABLE::TESClass;
		inline static constexpr auto FORMTYPE = FormType::Class;

		// members
		CLASS_DATA data;  // 70
	};
	static_assert(sizeof(TESClass) == 0xA8);
}
