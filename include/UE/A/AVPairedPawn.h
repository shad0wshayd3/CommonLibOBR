#pragma once

#include "UE/A/ACharacter.h"
#include "UE/E/EGroundMaterialType.h"
#include "UE/E/EOblivionAnimGroup.h"
#include "UE/E/EVActionType.h"
#include "UE/E/EVActorValues.h"
#include "UE/E/EVAnimAction.h"
#include "UE/E/EVBloodColor.h"
#include "UE/E/EVLifeState.h"
#include "UE/E/EVRagdollSetup.h"
#include "UE/E/EVSkinType.h"
#include "UE/F/FGameplayTagContainer.h"
#include "UE/F/FPoseSnapshot.h"
#include "UE/F/FVBufferedInputTag.h"
#include "UE/F/FVMovementInputThresholds.h"
#include "UE/F/FVPawnKnockdownRequest.h"
#include "UE/F/FVPerceptionState.h"
#include "UE/I/IReactToFreezeInterface.h"
#include "UE/I/IVAudioPlayable.h"
#include "UE/I/IVPhysicsControllable.h"
#include "UE/I/IVTransformPairable.h"
#include "UE/T/TBaseDynamicDelegate.h"
#include "UE/T/TMulticastDelegate.h"
#include "UE/T/TSoftClassPtr.h"
#include "UE/T/TSoftObjectPtr.h"

namespace UE
{
	class AVClairvoyanceVFXBlueprint;
	class AVPropItem;
	class AVShield;
	class AVWeapon;
	class FLinearColor;
	class FVHitReactEvent;
	class UAkAudioEvent;
	class UAnimSequence;
	class UAnimSequenceBase;
	class UBoxComponent;
	class UCurveFloat;
	class UMeshComponent;
	class UPhysicalAnimationComponent;
	class USoundBase;
	class UStaticMeshComponent;
	class UStaticMeshSocket;
	class UTESEffectShader;
	class UVActiveEffectsPairingComponent;
	class UVActorBehaviorBase;
	class UVActorBehaviorMap;
	class UVActorValuesPairingComponent;
	class UVAltarAIBlackboard;
	class UVAltarAkComponent;
	class UVAnimationPairingComponent;
	class UVCharacterFadeInOutComponent;
	class UVCharacterStatePairingComponent;
	class UVMergedSkeletalMeshComponent;
	class UVPairedPawnMovementComponent;
	class UVPairedPawnStateMachineComponent;
	class UVPawnAnimatedAction;
	class UVPawnSoundPairingComponent;
	class UVPhysicsControllerComponent;
	class UVStatusEffectOnPawn;
	class UVStatusEffectToDelete;
	class UVTESObjectRefComponent;
	class UVTransformPairingComponent;
	class UVWeaponsPairingComponent;
	class UWidgetComponent;

	using FOnActorValueChanged = TBaseDynamicDelegate<FNotThreadSafeDelegateMode, void, EVActorValues, float, float, float, float>;
	using FOnAnimatedActionStartedDelegate = TBaseDynamicMulticastDelegate<FNotThreadSafeDelegateMode, void, UVPawnAnimatedAction*>;
	using FOnEnterLowFatigueState = TBaseDynamicMulticastDelegate<FNotThreadSafeDelegateMode, void>;
	using FOnExitLowFatigueState = TBaseDynamicMulticastDelegate<FNotThreadSafeDelegateMode, void>;
	using FOnRequestLinkDynamicAnimLayers = TBaseDynamicMulticastDelegate<FNotThreadSafeDelegateMode, void>;
	using FOnTextureEffectStart = TBaseDynamicMulticastDelegate<FNotThreadSafeDelegateMode, void, UTESEffectShader*, const TArray<FLinearColor>&, const TArray<UStaticMeshComponent*>&, float>;
	using FOnTextureEffectStop = TBaseDynamicMulticastDelegate<FNotThreadSafeDelegateMode, void>;
	using FOnTextureEffectReset = TBaseDynamicMulticastDelegate<FNotThreadSafeDelegateMode, void>;
	using FVPhysicsSimulationStartDelegate = TBaseDynamicMulticastDelegate<FNotThreadSafeDelegateMode, void>;
	using FVPhysicsSimulationStopDelegate = TBaseDynamicMulticastDelegate<FNotThreadSafeDelegateMode, void>;

	class AVPairedPawn :
		public ACharacter,
		public IReactToFreezeInterface,
		public IVPhysicsControllable,
		public IVTransformPairable,
		public IVAudioPlayable
	{
	public:
		UE_DEFINE_UOBJECT(AVPairedPawn, ACharacter, "Altar", "VPairedPawn");

		class VFAttackInfo
		{
		public:
			// members
			bool                                 isFromWeapon;          // 000
			bool                                 isAttackFinished;      // 001
			FVector                              startLocation;         // 008
			FVector                              endLocation;           // 020
			FName                                boneName;              // 038
			TWeakObjectPtr<UStaticMeshComponent> weaponComponent;       // 040
			TWeakObjectPtr<UStaticMeshSocket>    weaponSocket;          // 048
			FVector                              wantedDirection;       // 050
			FVector                              bloodWantedDirection;  // 068
		};
		static_assert(sizeof(VFAttackInfo) == 0x80);

		// override
		virtual ~AVPairedPawn();  // 000

		// add
		virtual UVActorBehaviorBase*    GetBehaviorForTag_Implementation(const FGameplayTag& a_actionTag);                                                                                   //
		virtual void                    OnChangeActionState_Implementation(EVActionType a_actionState);                                                                                      //
		virtual void                    ResetToDefault();                                                                                                                                    //
		virtual bool                    CanBeTeleportedToNavigableSpot();                                                                                                                    //
		virtual bool                    CanUseAimOffset();                                                                                                                                   //
		virtual void                    OnWeaponChanged(const AVWeapon* a_weapon);                                                                                                           //
		virtual void                    OnTorchVisibilityChanged(const AActor* a_torch, bool a_equipping);                                                                                   //
		virtual void                    TryLinkConversationIdle();                                                                                                                           //
		virtual void                    TryLinkTorch();                                                                                                                                      //
		virtual void                    OnShieldChanged(const AVShield* a_shield, bool a_equipping);                                                                                         //
		virtual void                    UpdateDrawnArrowVisibility();                                                                                                                        //
		virtual void                    OnSeamlessTravelEnded();                                                                                                                             //
		virtual void                    CallTextureEffectBroadcastStart(const UVStatusEffectOnPawn* a_statusEffect);                                                                         //
		virtual void                    CallTextureEffectBroadcastStop();                                                                                                                    //
		virtual void                    UpdateFakeRootLocation(float a_deltaTime);                                                                                                           //
		virtual void                    SetPropertiesDefaultFromInitialSettings();                                                                                                           //
		virtual void                    DoCalculateLightingValues();                                                                                                                         //
		virtual USkeletalMeshComponent* GetBodyMesh();                                                                                                                                       //
		virtual TArray<UMeshComponent*> GetAllVisibleMeshComponents_Implementation(bool a_visible);                                                                                          //
		virtual EVBloodColor            GetBloodColor();                                                                                                                                     //
		virtual void                    SendMeleeHitOnPairedPawn(AVPairedPawn* a_pawn, bool a_powerAttack, float a_sneakDamageMult);                                                         //
		virtual FVector                 GetInteractionAimingDirectionVector();                                                                                                               //
		virtual FVector                 GetCombatAimingDirectionVector();                                                                                                                    //
		virtual FVector                 GetProjectileDirectionVector(const FVector& a_spawnLocation);                                                                                        //
		virtual FVector                 GetSpellProjectileSpawnLocation(FName a_castingSocket);                                                                                              //
		virtual FVector                 GetBowAimingDirectionVector();                                                                                                                       //
		virtual FVector                 GetAimingStartPosition();                                                                                                                            //
		virtual UVPawnAnimatedAction*   PlayAnimatedAction(FGameplayTag a_actionTag, float a_desiredDuration, std::int32_t a_animationIndex, bool a_lockMovement, float a_yawRotationMult);  //
		virtual void                    OnLoadFinished();                                                                                                                                    //
		virtual bool                    IsTargetInFOV(AVPairedPawn* a_target);                                                                                                               //
		virtual FVector                 GetPerceptionRaycastStartLocation(bool a_eyeLevel);                                                                                                  //
		virtual float                   GetReach();                                                                                                                                          //

		// members
		float                                                                        turnInPlaceAngleThreshold;                       // 6C8
		float                                                                        actorForwardPoseOffset;                          // 6CC
		FVector                                                                      lookAtPoint;                                     // 6D0
		bool                                                                         shouldUseLookAtPoint;                            // 6E8
		bool                                                                         inEntityDebugMode;                               // 6E9
		FOnEnterLowFatigueState                                                      onEnterLowFatigueState;                          // 6F0
		FOnExitLowFatigueState                                                       onExitLowFatigueState;                           // 700
		FOnActorValueChanged                                                         actorValueChangedDelegate_Paralysis;             // 710
		TObjectPtr<USceneComponent>                                                  fakeRoot;                                        // 720
		TArray<TObjectPtr<UPrimitiveComponent>>                                      secondaryColliders;                              // 728
		TObjectPtr<UCapsuleComponent>                                                physicsBodyCollider;                             // 738
		TObjectPtr<UBoxComponent>                                                    worldLimitDetectionBox;                          // 740
		TObjectPtr<USkeletalMeshComponent>                                           mainSkeletalMeshComponent;                       // 748
		TObjectPtr<UStaticMeshComponent>                                             drawnArrowMeshComponent;                         // 750
		TObjectPtr<UVPairedPawnStateMachineComponent>                                stateMachineComponent;                           // 758
		TObjectPtr<UVMergedSkeletalMeshComponent>                                    mergedMeshComponent;                             // 760
		TObjectPtr<UActorComponent>                                                  statusEffectComponent;                           // 768
		TObjectPtr<UVPairedPawnMovementComponent>                                    pairedPawnMovementComponent;                     // 770
		TObjectPtr<UWidgetComponent>                                                 pawnDebugInfoWidgetComponent;                    // 778
		TObjectPtr<UWidgetComponent>                                                 entityDetailsDebugWidgetComponent;               // 780
		TObjectPtr<UVPhysicsControllerComponent>                                     physicsControllerComponent;                      // 788
		TObjectPtr<UVAltarAkComponent>                                               akAudioComponent;                                // 790
		TObjectPtr<UPhysicalAnimationComponent>                                      physicalAnimationComponent;                      // 798
		TObjectPtr<UVCharacterFadeInOutComponent>                                    characterFadeInOutComponent;                     // 7A0
		FOnRequestLinkDynamicAnimLayers                                              onRequestLinkDynamicAnimLayers;                  // 7A8
		TObjectPtr<UVTESObjectRefComponent>                                          tesRefComponent;                                 // 7B8
		TObjectPtr<UVTransformPairingComponent>                                      transformPairingComponent;                       // 7C0
		TObjectPtr<UVAnimationPairingComponent>                                      animationPairingComponent;                       // 7C8
		TObjectPtr<UVPawnSoundPairingComponent>                                      pawnSoundPairingComponent;                       // 7D0
		TObjectPtr<UVWeaponsPairingComponent>                                        weaponsPairingComponent;                         // 7D8
		TObjectPtr<UVCharacterStatePairingComponent>                                 oblivionActorStatePairingComponent;              // 7E0
		TObjectPtr<UVActorValuesPairingComponent>                                    actorValuesPairingComponent;                     // 7E8
		TObjectPtr<UVActiveEffectsPairingComponent>                                  activeEffectsPairingComponent;                   // 7F0
		float                                                                        lightingUpdateFrequency;                         // 7F8
		float                                                                        currentLightingValue;                            // 7FC
		float                                                                        currentLightingValueWithTorch;                   // 800
		bool                                                                         doesDetectionLightingAllowShadowOcclusionTests;  // 804
		TObjectPtr<USoundBase>                                                       hitSoundCue;                                     // 808
		bool                                                                         inCombatStance;                                  // 810
		bool                                                                         isImmuneToShieldBashEffect;                      // 811
		TSet<AActor*>                                                                allowedMeleeTargets;                             // 818
		bool                                                                         restrictedMeleeTargeting;                        // 868
		float                                                                        yawRotationDelta;                                // 86C
		UAnimSequenceBase*                                                           specialAnimSequence;                             // 870
		UAnimSequence*                                                               dynamicAnimSequence;                             // 878
		FPoseSnapshot                                                                lastPoseSnapshot;                                // 880
		bool                                                                         isRagdollFacingUp;                               // 8B8
		EOblivionAnimGroup                                                           currentSpellCastAnimGroup;                       // 8B9
		bool                                                                         isLanding;                                       // 8BA
		bool                                                                         useRotationSpeedCurve;                           // 8BB
		TObjectPtr<UCurveFloat>                                                      rotationSpeedCurve;                              // 8C0
		TMap<FGameplayTag, FVMovementInputThresholds>                                movementInputThresholdsPerMaxGait;               // 8C8
		FOnTextureEffectStart                                                        onTextureEffectStart;                            // 918
		FOnTextureEffectStop                                                         onTextureEffectStop;                             // 928
		FOnTextureEffectReset                                                        onTextureEffectReset;                            // 938
		TMulticastDelegate<void(void), FDefaultDelegateUserPolicy>                   onMovementStopped;                               // 948
		FTimerHandle                                                                 againstBorderRegionTimerHandle;                  // 960
		TSet<AActor*>                                                                overlappingBorders;                              // 968
		float                                                                        shouldersHeight;                                 // 9B8
		float                                                                        shouldersHalfWidth;                              // 9BC
		float                                                                        detectionLightingBottomPointHeight;              // 9C0
		float                                                                        detectionLightingCenterHeight;                   // 9C4
		bool                                                                         interpolateFakeRootLocation;                     // 9C8
		bool                                                                         displayFakeRootLocationDebug;                    // 9C9
		bool                                                                         interpolateFakeRootOnlyZAxis;                    // 9CA
		TSoftObjectPtr<UCurveFloat>                                                  fakeRootDistanceInterpSpeedFactorCurve;          // 9D0
		TSoftObjectPtr<UCurveFloat>                                                  fakeRootVelocityInterpSpeedFactorCurve;          // 9F8
		float                                                                        maxFakeRootDistanceFromCapsule;                  // A20
		float                                                                        timeToRejoinRootWhenStoppingFakeRootInterp;      // A24
		FGameplayTagContainer                                                        tagsPreventingFakeRootInterp;                    // A28
		FVector                                                                      initialFakeRootCapsuleOffset;                    // A48
		float                                                                        timeLeftForFakeRootToRejoinRoot;                 // A60
		bool                                                                         isFakeRootRejoiningCapsule;                      // A64
		bool                                                                         isFakeRootJoinedToCapsule;                       // A65
		FVector                                                                      lastTickFakeRootLocation;                        // A68
		FVector                                                                      lastFakeRootUpdateVelocity;                      // A80
		FTimerHandle                                                                 changeMaterialEffectTimerHandle;                 // A98
		FTimerHandle                                                                 sendAttackFollowThroughTimerHandle;              // AA0
		TMulticastDelegate<void(const FVHitReactEvent&), FDefaultDelegateUserPolicy> onPawnHitReaction;                               // AA8
		FOnAnimatedActionStartedDelegate                                             onAnimatedActionStarted;                         // AC0
		TObjectPtr<UVPawnAnimatedAction>                                             currentAnimatedAction;                           // AD0
		FGameplayTagContainer                                                        hitReactIgnoredTags;                             // AD8
		TArray<TObjectPtr<AVPropItem>>                                               currentPropItemsInUse;                           // AF8
		bool                                                                         canEverRun;                                      // B08
		EGroundMaterialType                                                          groundMaterialType;                              // B09
		FTimerHandle                                                                 lightingUpdateTimerHandle;                       // B10
		std::uint64_t                                                                lastLightingUpdateFrame;                         // B18
		bool                                                                         isPlayer;                                        // B20
		EVRagdollSetup                                                               ragdollSetup;                                    // B21
		EVLifeState                                                                  lifeState;                                       // B22
		FName                                                                        aliveProfileName;                                // B24
		FName                                                                        unconsciousProfileName;                          // B2C
		FName                                                                        currentConstraintProfile;                        // B34
		EVAnimAction                                                                 oblivionAnimAction;                              // B3C
		std::byte                                                                    controllerDesiredRotationRate[0x20];             // B40 - TOptional<FRotator>
		TScriptDelegate<FNotThreadSafeDelegateMode>                                  loadFinishedHandle;                              // B60
		bool                                                                         inDebugPerceptionMode;                           // B70
		TObjectPtr<UVAltarAIBlackboard>                                              aiBlackboard;                                    // B78
		FVPhysicsSimulationStartDelegate                                             onPhysicsSimulationStarted;                      // B80
		FVPhysicsSimulationStopDelegate                                              onPhysicsSimulationStopped;                      // B90
		FGameplayTagContainer                                                        gameplayTags;                                    // BA0
		TArray<FVBufferedInputTag>                                                   bufferedInputTags;                               // BC0
		FGameplayTagContainer                                                        animTags;                                        // BD0
		FGameplayTagContainer                                                        lastAnimTags;                                    // BF0
		TSoftClassPtr<UVActorBehaviorMap>                                            behaviorMap;                                     // C10
		float                                                                        unarmedAttackReach;                              // C38
		float                                                                        perceptionUpdateFrequency;                       // C3C
		FTimerHandle                                                                 perceptionUpdateTimerHandle;                     // C40
		std::uint64_t                                                                lastPerceptionUpdateFrame;                       // C48
		bool                                                                         isStickyCollisionStateEnabled;                   // C50
		std::int32_t                                                                 pawnHitDuringStickyCollisionCounter;             // C54
		float                                                                        currentDodgeCooldown;                            // C58
		float                                                                        currentPushbackCooldown;                         // C5C
		bool                                                                         shouldBePushedOnImpactWithPawn;                  // C60
		FVector                                                                      deintersectionForce;                             // C68
		TMap<AVPairedPawn*, FVPerceptionState>                                       perceptionStateList;                             // C80
		TArray<TObjectPtr<UVStatusEffectOnPawn>>                                     statusEffectsList;                               // CD0
		TArray<TObjectPtr<UVStatusEffectToDelete>>                                   statusEffectsToDeleteList;                       // CE0
		TObjectPtr<UVStatusEffectOnPawn>                                             highestPriorityStatusEffect;                     // CF0
		TObjectPtr<UVStatusEffectOnPawn>                                             secondPriorityStatusEffect;                      // CF8
		TObjectPtr<UVStatusEffectOnPawn>                                             enchantPriorityStatusEffect;                     // D00
		EVSkinType                                                                   skinType;                                        // D08
		bool                                                                         isOverEncumbered;                                // D09
		bool                                                                         isSprintRequested;                               // D0A
		bool                                                                         isCastingSpellWithStaff;                         // D0B
		float                                                                        spellProjectileSpeed;                            // D0C
		float                                                                        actorBlinkDelayMin;                              // D10
		float                                                                        actorBlinkDelayMax;                              // D14
		float                                                                        actorBlinkDuration;                              // D18
		TObjectPtr<UAkAudioEvent>                                                    painEvent;                                       // D20
		TObjectPtr<UAkAudioEvent>                                                    footstepEvent;                                   // D28
		TObjectPtr<UAkAudioEvent>                                                    blockEvent;                                      // D30
		TObjectPtr<UAkAudioEvent>                                                    impactEvent;                                     // D38
		TObjectPtr<UAkAudioEvent>                                                    whooshEvent;                                     // D40
		TObjectPtr<UAkAudioEvent>                                                    equipEvent;                                      // D48
		TObjectPtr<UAkAudioEvent>                                                    unequipEvent;                                    // D50
		TObjectPtr<UAkAudioEvent>                                                    damageRumbleEvent;                               // D58
		float                                                                        strengthEncumbranceMult;                         // D60
		AVPairedPawn::VFAttackInfo                                                   attackInfo;                                      // D68
		AVPairedPawn*                                                                lastAttacker;                                    // DE8
		TWeakObjectPtr<AVClairvoyanceVFXBlueprint>                                   clairvoyanceBP;                                  // DF0
		FVPawnKnockdownRequest                                                       latestKnockdownRequest;                          // DF8
		bool                                                                         waitingToPlayLandingFootstep;                    // E20
		FName                                                                        bufferedFootstepAction;                          // E24
	};
	static_assert(sizeof(AVPairedPawn) == 0xE30);
}
