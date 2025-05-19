#pragma once

#include "RE/E/EffectShaderData.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class TESEffectShader :
		public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESEffectShader;
		inline static constexpr auto VTABLE = VTABLE::TESEffectShader;
		inline static constexpr auto FORMTYPE = FormType::EffectShader;

		// members
		EffectShaderData data;  // 30
	};
	static_assert(sizeof(TESEffectShader) == 0x90);
}
