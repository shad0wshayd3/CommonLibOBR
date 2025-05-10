#pragma once

#include "RE/N/NiTPointerMap.h"

namespace RE
{
	class TESConnectedPoint;
	class TESWorldSpace;

	class TESRoad :
		public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESRoad;
		inline static constexpr auto VTABLE = VTABLE::TESRoad;
		inline static constexpr auto FORMTYPE = FormType::Road;

		// members
		std::uint32_t                                                   pointCount;   // 30
		NiTPointerMap<std::uint32_t, BSSimpleList<TESConnectedPoint*>*> pointMap;     // 38
		TESWorldSpace*                                                  parentWorld;  // 58
	};
	static_assert(sizeof(TESRoad) == 0x60);
}
