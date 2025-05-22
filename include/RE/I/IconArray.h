#pragma once

#include "RE/H/HUDEffectIcon.h"
#include "RE/N/NiTArray.h"

namespace RE
{
	class HUDEffectIcon;

	class IconArray :
		public NiTLargeArray<HUDEffectIcon>
	{
	public:
		virtual ~IconArray() override;

		// add
		virtual HUDEffectIcon* RemoveAt(std::uint32_t a_index);  // 01

		// members
		std::uint8_t numFading;  // 00
	};
	static_assert(sizeof(IconArray) == 0x28);
}
