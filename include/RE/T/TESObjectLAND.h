#pragma once

#include "RE/N/NiPoint2.h"
#include "RE/N/NiPointer.h"
#include "RE/N/NiTPointerMap.h"
#include "RE/O/OBJ_LAND.h"
#include "RE/T/TESChildCell.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class bhkRigidBody;
	class hkMoppCode;
	class NiColorA;
	class NiLines;
	class NiNode;
	class NiPoint3;
	class TESGrassAreaParam;
	class TESLandTexture;
	class TESObjectCELL;

	class TESObjectLAND :
		public TESForm,
		public TESChildCell
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESObjectLAND;
		inline static constexpr auto VTABLE = VTABLE::TESObjectLAND;
		inline static constexpr auto FORMTYPE = FormType::Land;

		struct LoadedLandData
		{
		public:
			// members
			NiNode**                                          mesh;                 // 000
			NiPoint3**                                        vertices;             // 008
			NiPoint3**                                        normals;              // 010
			NiColorA**                                        colors;               // 018
			bool**                                            normalsSet;           // 020
			NiPointer<NiLines>                                border;               // 028
			NiPoint2                                          heightExtents;        // 030
			TESLandTexture*                                   defQuadTexture[4];    // 038
			TESLandTexture**                                  quadTextureArray[4];  // 058
			float**                                           percentArrays[4];     // 078
			hkMoppCode*                                       moppCode;             // 098
			NiTPointerMap<std::uint32_t, TESGrassAreaParam**> grassMap[4];          // 0A0
			NiPointer<bhkRigidBody>                           landRB;               // 120
			std::int32_t                                      cellX;                // 128
			std::int32_t                                      cellY;                // 12C
		};
		static_assert(sizeof(LoadedLandData) == 0x130);

		// override (TESForm)
		virtual ~TESObjectLAND() override;                                                                                   // 04
		virtual bool     Load(TESFile* a_file) override;                                                                     // 07
		virtual void     Save() override;                                                                                    // 09
		virtual bool     SavesBefore(TESForm* a_form) override;                                                              // 0D
		virtual TESForm* CreateDuplicateForm(bool a_createEditorID, NiTPointerMap<TESForm*, TESForm*>* a_copyMap) override;  // 0E
		virtual void     SetAltered(bool a_set) override;                                                                    // 24
		virtual void     Copy(TESForm* a_srcForm) override;                                                                  // 2D
		virtual bool     BelongsInGroup(FORM* a_form, bool a_allowParentGroups, bool a_currentOnly) override;                // 2F

		// members
		OBJ_LAND        data;                      // 38
		TESObjectCELL*  parentCell;                // 40
		LoadedLandData* loadedData;                // 48
		std::uint8_t    lastLoadFileCompileIndex;  // 50
	};
	static_assert(sizeof(TESObjectLAND) == 0x58);
}
