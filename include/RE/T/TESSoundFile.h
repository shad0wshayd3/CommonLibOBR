#pragma once

#include "RE/B/BSStringT.h"
#include "RE/B/BaseFormComponent.h"

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
