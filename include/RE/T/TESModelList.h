#pragma once

#include "RE/B/BSTList.h"
#include "RE/B/BaseFormComponent.h"
#include "RE/T/TESTextureListArray.h"

namespace RE
{
	struct TESModelList :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESModelList;
		inline static constexpr auto VTABLE = VTABLE::TESModelList;

		// members
		BSSimpleList<const char*> filenames;         // 08
		TESTextureListArray       textureListArray;  // 18
	};
	static_assert(sizeof(TESModelList) == 0x28);
}
