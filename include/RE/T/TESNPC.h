#pragma once

#include "RE/F/FR2MatrixVTC.h"
#include "RE/N/NPC_DATA.h"
#include "RE/N/NiPointer.h"
#include "RE/N/NiTArray.h"
#include "RE/T/TESActorBase.h"
#include "RE/T/TESRaceForm.h"

namespace RE
{
	class BSFaceGenNiNode;
	class FaceGenUndo;
	class NiTexture;
	class TESClass;
	class TESCombatStyle;
	class TESEyes;
	class TESHair;

	class TESNPC :
		public TESActorBase,
		public TESRaceForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESNPC;
		inline static constexpr auto VTABLE = VTABLE::TESNPC;
		inline static constexpr auto FORMTYPE = FormType::NPC;

		// members
		NPC_DATA                   data;                          // 1B8
		TESClass*                  _class;                        // 1D0
		FR2MatrixVTC<float>        raceFaceOffsetCoord[2][2];     // 1D8
		FR2MatrixVTC<float>        vampireFaceOffsetCoord[2][2];  // 258
		TESHair*                   hair;                          // 2D8
		float                      hairLength;                    // 2E0
		TESEyes*                   eyeColor;                      // 2E8
		NiPointer<BSFaceGenNiNode> headBiped;                     // 2F0
		NiPointer<BSFaceGenNiNode> headSkinned;                   // 2F8
		NiPointer<NiTexture>       bodyModTexture;                // 300
		std::uint16_t              lastRaceFaceNum;               // 308
		TESCombatStyle*            combatStyle;                   // 310
		std::uint32_t              hairColor;                     // 318
		std::uint32_t              fileOffset;                    // 31C
		NiTArray<FaceGenUndo*>     faceGenUndoStates;             // 320
	};
	static_assert(sizeof(TESNPC) == 0x338);
}
