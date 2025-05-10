#pragma once

#include "RE/B/BSTList.h"
#include "RE/N/NiPointer.h"
#include "RE/N/NiTArray.h"
#include "RE/N/NiTPointerMap.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class NiNode;
	class TESObjectCELL;
	class TESObjectREFR;
	class TESPathGridPoint;
	struct INTERGRID_CONNECTION;

	class TESPathGrid :
		public TESForm,
		public TESChildCell
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESPathGrid;
		inline static constexpr auto VTABLE = VTABLE::TESPathGrid;
		inline static constexpr auto FORMTYPE = FormType::PathGrid;

		// members
		NiPointer<NiNode>                                               _3DNode;                   // 38
		TESObjectCELL*                                                  parentCell;                // 40
		NiTArray<TESPathGridPoint*>*                                    pointArray;                // 48
		BSSimpleList<INTERGRID_CONNECTION*>                             interGridConnections;      // 50
		std::uint16_t                                                   numPoints;                 // 60
		NiTPointerMap<TESObjectREFR*, BSSimpleList<TESPathGridPoint*>*> linkedPoints;              // 68
		NiTPointerMap<std::uint32_t, BSSimpleList<TESPathGridPoint*>*>  gridPoints;                // 88
		std::uint8_t                                                    lastLoadFileCompileIndex;  // A8
	};
	static_assert(sizeof(TESPathGrid) == 0xB0);
}
