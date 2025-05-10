#pragma once

#include "RE/T/TESBoundObject.h"

namespace RE
{
	class TESSubSpace :
		public TESBoundObject
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESSubSpace;
		inline static constexpr auto VTABLE = VTABLE::TESSubSpace;
		inline static constexpr auto FORMTYPE = FormType::SubSpace;

		// members
		std::uint16_t xDim;    // 48
		std::uint16_t yDim;    // 4A
		std::uint16_t zDim;    // 4C
		float         radius;  // 50
	};
	static_assert(sizeof(TESSubSpace) == 0x58);
}
