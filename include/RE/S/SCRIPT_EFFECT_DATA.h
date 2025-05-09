#pragma once

namespace RE
{
	struct SCRIPT_EFFECT_DATA
	{
	public:
		// members
		bool  scriptEffectStart;   // 00
		bool  scriptEffectFinish;  // 01
		float secondsElapsed;      // 04
	};
	static_assert(sizeof(SCRIPT_EFFECT_DATA) == 0x08);
}
