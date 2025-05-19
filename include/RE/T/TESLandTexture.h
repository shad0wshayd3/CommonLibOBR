#pragma once

#include "RE/B/BSTList.h"
#include "RE/N/NiPointer.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESLeveledList.h"
#include "RE/T/TESTexture.h"
#include "RE/T/TEXTURE_HAVOK_DATA.h"

namespace RE
{
	class NiSourceTexture;
	class TESGrass;

	class TESLandTexture :
		public TESForm,
		public TESTexture
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESLandTexture;
		inline static constexpr auto VTABLE = VTABLE::TESLandTexture;
		inline static constexpr auto FORMTYPE = FormType::LandTexture;

		// members
		NiPointer<NiSourceTexture> image;             // 48
		TEXTURE_HAVOK_DATA         havokData;         // 50
		std::uint8_t               specularExponent;  // 53
		BSSimpleList<TESGrass*>    textureGrassList;  // 58
	};
	static_assert(sizeof(TESLandTexture) == 0x68);
}
