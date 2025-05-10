#pragma once

#include "RE/T/TESBoundObject.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class TESGrass :
		public TESBoundObject,
		public TESModel
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESGrass;
		inline static constexpr auto VTABLE = VTABLE::TESGrass;
		inline static constexpr auto FORMTYPE = FormType::Grass;

		enum class GRASS_WATER_STATE : std::int32_t
		{
			kAboveOnlyAtLeast,
			kAboveOnlyAtMost,
			kBelowOnlyAtLeast,
			kBelowOnlyAtMost,
			kBothAtLeast,
			kBothAtMost,
			kBothAtMostAbove,
			kBothAtMostBelow,
		};

		struct GRASS_DATA
		{
		public:
			// members
			std::uint8_t      density;                 // 00
			std::uint8_t      minSlopeDegrees;         // 01
			std::uint8_t      maxSlopeDegrees;         // 02
			std::uint16_t     distanceFromWaterLevel;  // 04
			GRASS_WATER_STATE underwater;              // 08
			float             positionRange;           // 0C
			float             heightRange;             // 10
			float             colorRange;              // 14
			float             wavePeriod;              // 18
			std::uint8_t      flags;                   // 1C
		};
		static_assert(sizeof(GRASS_DATA) == 0x20);

		// members
		GRASS_DATA data;  // 78
	};
	static_assert(sizeof(TESGrass) == 0x98);
}
