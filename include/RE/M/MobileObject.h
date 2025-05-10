#pragma once

#include "RE/T/TESObjectREFR.h"

namespace RE
{
	class BaseProcess;
	class bhkCharacterController;

	class MobileObject :
		public TESObjectREFR
	{
	public:
		inline static constexpr auto RTTI = RTTI::MobileObject;
		inline static constexpr auto VTABLE = VTABLE::MobileObject;

		// override (TESForm)
		virtual ~MobileObject() override;                                                                    // 04
		virtual std::uint16_t GetSaveSize(std::uint32_t a_changeFlags) override;                             // 13
		virtual void          SaveGame(std::uint32_t a_changeFlags) override;                                // 14
		virtual void          LoadGame(std::uint32_t a_flags, std::uint32_t a_currentFlags) override;        // 15
		virtual void          InitLoadGame(std::uint32_t a_flags, std::uint32_t a_oldFlags) override;        // 16
		virtual void          FinishInitLoadGame(std::uint32_t a_flags, std::uint32_t a_oldFlags) override;  // 17
		virtual void          Revert(std::uint32_t a_flags) override;                                        // 18
		virtual void          SetDelete(bool a_set) override;                                                // 23
		virtual bool          DetachHavok() override;                                                        // 57
		virtual void          InitHavok() override;                                                          // 58
		virtual NiAVObject*   Load3D() override;                                                             // 59
		virtual NiPoint3*     GetBoundMin() override;                                                        // 5C
		virtual NiPoint3*     GetBoundMax() override;                                                        // 5D
		virtual void          MoveHavok(bool a_forceRecurse) override;                                       // 64
		virtual void          SetParentCell(TESObjectCELL* a_cell) override;                                 // 6B
		virtual void          OnModelAttached() override;                                                    // 6F

		// add
		virtual void                    SendPositionPairingHandler();                                             // 77
		virtual bool                    MoveToHigh();                                                             // 78
		virtual bool                    MoveToLow();                                                              // 79
		virtual bool                    MoveToMiddleLow();                                                        // 7A
		virtual bool                    MoveToMiddleHigh();                                                       // 7B
		virtual bhkCharacterController* Move(float a_deltaTime, NiPoint3& a_deltaMove, std::uint32_t a_moveDir);  // 7C
		virtual bhkCharacterController* Jump();                                                                   // 7D
		virtual void                    SetAvoidanceDisabled(bool a_value);                                       // 7E
		virtual void                    Process(float a_delta);                                                   // 7F
		virtual bool                    ChangeProcessLevel();                                                     // 80
		virtual bool                    DetachCharController();                                                   // 81
		virtual void                    SetPosition(const NiPoint3& a_pos);                                       // 82
		virtual void                    GetLinearVelocity(NiPoint3& a_vel);                                       // 83
		virtual void                    EvaluateDetection(float a_number);                                        // 84
		virtual float                   GetDetectionTimer();                                                      // 85
		virtual void                    ReduceDetectionTimer();                                                   // 86
		virtual float                   GetHeading();                                                             // 87
		virtual void                    SetHeading(TESObjectREFR* a_targetReference);                             // 88
		virtual void                    SetHeading(float a_angle);                                                // 89
		virtual void                    SetSize(float a_radius);                                                  // 8A
		virtual bool                    GetRunsInLow();                                                           // 8B
		virtual float                   GetAcrobatics();                                                          // 8C
		virtual bool                    IsDying();                                                                // 8D
		virtual bool                    IsTransient();                                                            // 8E
		virtual void                    SetDisplayGeometry(bool a_value);                                         // 8F

		// members
		BaseProcess* currentProcess;          // 138
		float        lastCollisionCheckTime;  // 140
	};
	static_assert(sizeof(MobileObject) == 0x148);
}
