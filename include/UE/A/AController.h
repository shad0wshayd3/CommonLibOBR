#pragma once

#include "UE/A/AActor.h"
#include "UE/I/INavAgentInterface.h"
#include "UE/T/TBaseDynamicMulticastDelegate.h"
#include "UE/T/TMulticastDelegate.h"

namespace UE
{
	class ACharacter;
	class APawn;
	class APlayerState;
	class UDamageType;

	using FInstigatedAnyDamageSignature = TBaseDynamicMulticastDelegate<FNotThreadSafeDelegateMode, void, float, const UDamageType*, AActor*, AActor*>;
	using FOnPossessedPawnChanged = TBaseDynamicMulticastDelegate<FNotThreadSafeDelegateMode, void, APawn*, APawn*>;
	using FPawnChangedSignature = TMulticastDelegate<void(APawn*)>;

	class AController :
		public AActor,
		public INavAgentInterface
	{
	public:
		UE_DEFINE_UOBJECT(AController, AActor, "Engine", "Controller");

		// override
		virtual ~AController();

		// add
		virtual bool     ClientSetRotation_Validate(FRotator a_rotation, bool a_resetCamera);                                                   //
		virtual void     ClientSetRotation_Implementation(FRotator a_rotation, bool a_resetCamera);                                             //
		virtual bool     ClientSetLocation_Validate(FVector a_location, FRotator a_rotation);                                                   //
		virtual void     ClientSetLocation_Implementation(FVector a_location, FRotator a_rotation);                                             //
		virtual void     AttachToPawn(APawn* a_pawn);                                                                                           //
		virtual void     DetachFromPawn();                                                                                                      //
		virtual void     AddPawnTickDependency(APawn* a_pawn);                                                                                  //
		virtual void     RemovePawnTickDependency(APawn* a_pawn);                                                                               //
		virtual void     ChangeState(FName a_state);                                                                                            //
		virtual FRotator GetControlRotation();                                                                                                  //
		virtual void     SetControlRotation(const FRotator& a_rotation);                                                                        //
		virtual void     SetInitialLocationAndRotation(const FVector& a_location, const FRotator& a_rotation);                                  //
		virtual bool     LineOfSightTo(const AActor* a_actor, FVector& a_viewPoint, bool a_alternate = false);                                  //
		virtual void     OnRep_Pawn();                                                                                                          //
		virtual void     OnRep_PlayerState();                                                                                                   //
		virtual void     SetPawn(APawn* a_pawn);                                                                                                //
		virtual AActor*  GetViewTarget();                                                                                                       //
		virtual FRotator GetDesiredRotation();                                                                                                  //
		virtual bool     IsLocalController();                                                                                                   //
		virtual void     CleanupPlayerState();                                                                                                  //
		virtual void     Possess(APawn* a_pawn);                                                                                                //
		virtual void     UnPossess();                                                                                                           //
		virtual void     OnPossess(APawn* a_pawn);                                                                                              //
		virtual void     OnUnPossess();                                                                                                         //
		virtual void     PawnPendingDestroy(APawn* a_pawn);                                                                                     //
		virtual void     InstigatedAnyDamage(float a_damage, const UDamageType* a_damageType, AActor* a_damagedActor, AActor* a_damageCauser);  //
		virtual void     InitPlayerState();                                                                                                     //
		virtual void     GameHasEnded(AActor* a_focus = nullptr, bool a_winner = false);                                                        //
		virtual void     GetPlayerViewPoint(FVector& a_location, FRotator& a_rotation);                                                         //
		virtual void     FailedToSpawnPawn();                                                                                                   //
		virtual void     StopMovement();                                                                                                        //
		virtual void     SetIgnoreMoveInput(bool a_ignore);                                                                                     //
		virtual void     ResetIgnoreMoveInput();                                                                                                //
		virtual bool     IsMoveInputIgnored();                                                                                                  //
		virtual void     SetIgnoreLookInput(bool a_ignore);                                                                                     //
		virtual void     ResetIgnoreLookInput();                                                                                                //
		virtual bool     IsLookInputIgnored();                                                                                                  //
		virtual void     ResetIgnoreInputFlags();                                                                                               //
		virtual void     CurrentLevelUnloaded();                                                                                                //
		virtual bool     ShouldParticipateInSeamlessTravel();                                                                                   //
		virtual void     BeginInactiveState();                                                                                                  //
		virtual void     EndInactiveState();                                                                                                    //

		// members
		TObjectPtr<APlayerState>      playerState;                    // 2A0
		TWeakObjectPtr<AActor>        startSpot;                      // 2A8
		FInstigatedAnyDamageSignature onInstigatedAnyDamage;          // 2B0
		FOnPossessedPawnChanged       onPossessedPawnChanged;         // 2C0
		FName                         stateName;                      // 2D0
		TObjectPtr<APawn>             pawn;                           // 2D8
		TWeakObjectPtr<APawn>         oldPawn;                        // 2E0
		TObjectPtr<ACharacter>        character;                      // 2E8
		TObjectPtr<USceneComponent>   transformComponent;             // 2F0
		FPawnChangedSignature         onNewPawn;                      // 2F8
		FRotator                      controlRotation;                // 310
		std::uint8_t                  attachToPawn: 1;                // 328:0
		std::uint8_t                  isPlayerController: 1;          // 328:1
		std::uint8_t                  canPossessWithoutAuthority: 1;  // 328:2
		std::uint8_t                  ignoreMoveInput;                // 329
		std::uint8_t                  ignoreLookInput;                // 330
	};
	static_assert(sizeof(AController) == 0x330);
}
