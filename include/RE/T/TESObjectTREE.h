#pragma once

#include "RE/N/NiPoint2.h"
#include "RE/N/NiTArray.h"
#include "RE/O/OBJ_TREE.h"
#include "RE/T/TESBoundTreeObject.h"
#include "RE/T/TESIconTree.h"
#include "RE/T/TESModelTree.h"

namespace RE
{
	class TESObjectTREE :
		public TESBoundTreeObject,
		public TESModelTree,
		public TESIconTree
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESObjectTREE;
		inline static constexpr auto VTABLE = VTABLE::TESObjectTREE;
		inline static constexpr auto FORMTYPE = FormType::Tree;

		// override (TESForm)
		virtual ~TESObjectTREE() override;                   // 04
		virtual bool Load(TESFile* a_file) override;         // 07
		virtual void Save() override;                        // 09
		virtual void InitItem() override;                    // 1B
		virtual void Copy(TESForm* a_srcForm) override;      // 2D
		virtual bool Compare(TESForm* a_copyForm) override;  // 2E

		// add
		virtual std::uint8_t  GetIndexForSeed(std::uint32_t a_seed);     // 4E
		virtual std::uint32_t GetSeedAtIndex(std::uint8_t a_index);      // 4F
		virtual OBJ_TREE*     GetData();                                 // 50
		virtual std::uint32_t GetRandomSeed();                           // 51
		virtual float         GetCurveScalar();                          // 52
		virtual void          SetCurveScalar(const float a_value);       // 53
		virtual float         GetMinimumLeafAngle();                     // 54
		virtual void          SetMinimumLeafAngle(const float a_value);  // 55
		virtual float         GetMaximumLeafAngle();                     // 56
		virtual void          SetMaximumLeafAngle(const float a_value);  // 57
		virtual float         GetBranchDimming();                        // 58
		virtual void          SetBranchDimming(const float a_value);     // 59
		virtual float         GetLeafDimming();                          // 5A
		virtual void          SetLeafDimming(const float a_value);       // 5B
		virtual float         GetShadowRadius();                         // 5C
		virtual void          SetShadowRadius(const float a_value);      // 5D
		virtual float         GetRockSpeed();                            // 5E
		virtual void          SetRockSpeed(const float a_value);         // 5F
		virtual float         GetRustleSpeed();                          // 60
		virtual void          SetRustleSpeed(const float a_value);       // 61

		// members
		NiTArray<std::uint32_t> seedArray;      // 90
		OBJ_TREE                data;           // A8
		NiPoint2                billboardSize;  // C8
	};
	static_assert(sizeof(TESObjectTREE) == 0xD0);
}
