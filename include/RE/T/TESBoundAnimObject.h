#pragma once

#include "RE/T/TESBoundObject.h"

namespace RE
{
	class TESBoundAnimObject : public TESBoundObject
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESBoundAnimObject;
		inline static constexpr auto VTABLE = VTABLE::TESBoundAnimObject;

		~TESBoundAnimObject() override;  // 04
	};
	static_assert(sizeof(TESBoundAnimObject) == 0x48);
}
