#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class TESHair :
		public TESForm,
		public TESFullName,
		public TESModel,
		public TESTexture
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESHair;
		inline static constexpr auto VTABLE = VTABLE::TESHair;
		inline static constexpr auto FORMTYPE = FormType::Hair;

		// members
		std::uint8_t flags;  // 90
	};
	static_assert(sizeof(TESHair) == 0x98);
}
