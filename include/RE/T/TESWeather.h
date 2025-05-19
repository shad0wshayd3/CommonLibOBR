#pragma once

#include "RE/B/BSTList.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class TESWeather :
		public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESWeather;
		inline static constexpr auto VTABLE = VTABLE::TESWeather;
		inline static constexpr auto FORMTYPE = FormType::Weather;

		enum class SoundType : std::int32_t
		{
			kDefault,
			kPrecipitation,
			kWind,
			kThunder,
		};

		class WeatherSound
		{
		public:
			// members
			TESFormID soundFormID;  // 00
			SoundType type;         // 04
		};
		static_assert(sizeof(WeatherSound) == 0x08);

		class WeatherSoundList :
			public BSSimpleList<WeatherSound*>
		{
		public:
		};
		static_assert(sizeof(WeatherSoundList) == 0x10);

		// members
		TESTexture       cloudTexture[2];   // 030
		TESModel         precipitation;     // 060
		std::uint8_t     weatherData[15];   // 090
		float            fogData[4];        // 0A0
		std::uint32_t    colorData[10][4];  // 0B0
		WeatherSoundList soundList;         // 150
		float            hdrData[14];       // 160
	};
	static_assert(sizeof(TESWeather) == 0x198);
}
