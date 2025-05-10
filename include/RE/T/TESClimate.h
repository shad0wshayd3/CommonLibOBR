#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESTexture.h"
#include "RE/T/TESWeatherList.h"

namespace RE
{
	class TESClimate :
		public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESClimate;
		inline static constexpr auto VTABLE = VTABLE::TESClimate;
		inline static constexpr auto FORMTYPE = FormType::Climate;

		// members
		TESModel       nightSky;       // 30
		TESWeatherList weatherList;    // 60
		TESTexture     skyObjects[2];  // 70
		std::uint8_t   data[6];        // A0
	};
	static_assert(sizeof(TESClimate) == 0xA8);
}
