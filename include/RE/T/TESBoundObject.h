#pragma once

#include "RE/T/TESObject.h"
#include "RE/T/TESObjectList.h"

namespace RE
{
	class NiNode;
	class NiPoint3;

	class TESBoundObject : public TESObject
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESBoundObject;
		inline static constexpr auto VTABLE = VTABLE::TESBoundObject;

		~TESBoundObject() override;  // 04

		// add
		virtual NiAVObject** Clone3D(TESObjectREFR* a_ref);                                                                                                                                                                   // 4A
		virtual bool*        ReplaceModel(const char* a_str);                                                                                                                                                                 // 4B
		virtual void*        CreateDistant3D(NiPoint3* a_loc, NiPoint3* a_rot, float* a_colors, std::uint32_t a_arraySize, std::uint32_t a_cellChunk, std::uint32_t a_cellKey, NiNode* a_instancedNode, NiNode* a_fullNode);  // 4C
	};
	static_assert(sizeof(TESBoundObject) == 0x48);
}
