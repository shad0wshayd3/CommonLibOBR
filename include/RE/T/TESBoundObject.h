#pragma once

#include "RE/T/TESObject.h"
#include "RE/T/TESObjectList.h"

namespace RE
{
	class NiNode;
	class NiPoint3;

	class TESBoundObject :
		public TESObject
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESBoundObject;
		inline static constexpr auto VTABLE = VTABLE::TESBoundObject;

		// override (TESObject)
		virtual ~TESBoundObject() override;                                                                                                                                     // 04
		virtual bool        Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, bool a_idFlag, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 33
		virtual NiAVObject* Clone3D(TESObjectREFR* a_ref, bool a_deepCopy) override;                                                                                            // 40
		virtual bool        ReplaceModel() override;                                                                                                                            // 44

		// add
		virtual NiAVObject** Clone3D(TESObjectREFR* a_ref);                                                                                                                                                                   // 4A
		virtual bool*        ReplaceModel(const char* a_str);                                                                                                                                                                 // 4B
		virtual void*        CreateDistant3D(NiPoint3* a_loc, NiPoint3* a_rot, float* a_colors, std::uint32_t a_arraySize, std::uint32_t a_cellChunk, std::uint32_t a_cellKey, NiNode* a_instancedNode, NiNode* a_fullNode);  // 4C
	};
	static_assert(sizeof(TESBoundObject) == 0x48);
}
