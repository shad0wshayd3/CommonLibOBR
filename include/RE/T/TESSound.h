#pragma once

#include "RE/B/BSStringT.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESSoundFile.h"

namespace RE
{
	class TESSound :
		public TESBoundAnimObject,
		public TESSoundFile
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESSound;
		inline static constexpr auto VTABLE = VTABLE::TESSound;
		inline static constexpr auto FORMTYPE = FormType::Sound;

		struct SOUND_DATA2
		{
		public:
			// members
			std::uint8_t  min;              // 00
			std::uint8_t  max;              // 01
			std::uint8_t  pitch;            // 02
			std::uint32_t flags;            // 04
			std::uint16_t attenuation;      // 08
			std::uint16_t timeConstraints;  // 0A
		};
		static_assert(sizeof(SOUND_DATA2) == 0x0C);

		// members
		BSString    formEditorID;  // 60
		SOUND_DATA2 data;          // 70
	};
	static_assert(sizeof(TESSound) == 0x80);
}
