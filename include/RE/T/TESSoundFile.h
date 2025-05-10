#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/B/BSStringT.h"

namespace RE
{
	class TESSoundFile :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESSoundFile;

		// members
		BSString soundFile;  // 08
	};
	static_assert(sizeof(TESSoundFile) == 0x18);
}
