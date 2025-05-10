#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class TESEyes :
		public TESForm,
		public TESFullName,
		public TESTexture
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESEyes;
		inline static constexpr auto VTABLE = VTABLE::TESEyes;
		inline static constexpr auto FORMTYPE = FormType::Eyes;

		// members
		std::uint8_t flags;  // 60
	};
	static_assert(sizeof(TESEyes) == 0x68);
}
