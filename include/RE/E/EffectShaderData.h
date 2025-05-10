#pragma once

namespace RE
{
	class EffectShaderData
	{
	public:
		// members
		std::uint8_t  flags;                       // 00
		std::int32_t  textureBlendModeSource;      // 04
		std::int32_t  textureBlendOperation;       // 08
		std::int32_t  textureZTestFunction;        // 0C
		std::uint32_t fillColor;                   // 10
		float         fillAlphaFadeInTime;         // 14
		float         fillAlphaFullTime;           // 18
		float         fillAlphaFadeOutTime;        // 1C
		float         fillAlphaPersistentPercent;  // 20
		float         fillAlphaPulseAmplitude;     // 24
		float         fillAlphaPulseFrequency;     // 28
		float         fillTextureUAnimSpeed;       // 2C
		float         fillTextureVAnimSpeed;       // 30
		float         edgeExponentValue;           // 34
		std::uint32_t edgeColor;                   // 38
		float         edgeAlphaFadeInTime;         // 3C
		float         edgeAlphaFullTime;           // 40
		float         edgeAlphaFadeOutTime;        // 44
		float         edgeAlphaPersistentPercent;  // 48
		float         edgeAlphaPulseAmplitude;     // 4C
		float         edgeAlphaPulseFrequency;     // 50
		float         fillAlphaFullPercent;        // 54
		float         edgeAlphaFullPercent;        // 58
	};
	static_assert(sizeof(EffectShaderData) == 0x5C);
}
