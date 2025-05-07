#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class BipedAnim;
	class NiAVObject;
	class TESObjectList;

	class TESObject : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESObject;
		inline static constexpr auto VTABLE = VTABLE::TESObject;

		~TESObject() override;  // 04

		// add
		virtual NiAVObject*  Load3D();                                        // 3C
		virtual bool         IsBoundAnimObject();                             // 3D
		virtual bool         IsAutoCalc();                                    // 3E
		virtual void         SetAutoCalc(bool a_autoCalc);                    // 3F
		virtual NiAVObject*  Clone3D(TESObjectREFR* a_ref, bool a_deepCopy);  // 40
		virtual void         UnClone3D(TESObjectREFR* a_ref);                 // 41
		virtual bool         IsMarker();                                      // 42
		virtual void         InitDefaultWorn();                               // 43
		virtual bool         ReplaceModel();                                  // 44
		virtual bool         ReplaceModel(BipedAnim* a_bipedAnim);            // 45
		virtual void         Set3D(NiAVObject* a_obj);                        // 46
		virtual unsigned int IncRef();                                        // 47
		virtual unsigned int DecRef();                                        // 48
		virtual NiAVObject*  LoadGraphics(TESObjectREFR* a_ref);              // 49

		// members
		TESObjectList* parentList;  // 30
		TESObject*     prev;        // 38
		TESObject*     next;        // 40
	};
	static_assert(sizeof(TESObject) == 0x48);
}
