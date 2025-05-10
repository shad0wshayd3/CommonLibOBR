#pragma once

#include "RE/B/BSStringT.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class TESGlobal :
		public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESGlobal;
		inline static constexpr auto VTABLE = VTABLE::TESGlobal;
		inline static constexpr auto FORMTYPE = FormType::Global;

		// members
		BSString     formEditorID;  // 30
		std::uint8_t type;          // 40
		float        value;         // 44
	};
	static_assert(sizeof(TESGlobal) == 0x48);
}
