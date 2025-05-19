#pragma once

#include "RE/T/TESObjectACTI.h"

namespace RE
{
	class TESFurniture :
		public TESObjectACTI
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESFurniture;
		inline static constexpr auto VTABLE = VTABLE::TESFurniture;
		inline static constexpr auto FORMTYPE = FormType::Furniture;

		// members
		std::int32_t furnitureFlags;  // B0
	};
	static_assert(sizeof(TESFurniture) == 0xB8);
}
