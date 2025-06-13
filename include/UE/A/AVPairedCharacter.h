#pragma once

#include "UE/A/AVPairedPawn.h"
#include "UE/E/EBipedModularBodySlot.h"
#include "UE/E/ECharacterSex.h"
#include "UE/E/EVCharacterRefreshSelector.h"
#include "UE/E/EVVoiceType.h"
#include "UE/F/FInitialEquipmentInfo.h"
#include "UE/F/FVCharacterBodyPartProperties.h"

namespace UE
{
	class AVPairedCreature;
	class FStreamableHandle;
	class UMotionWarpingComponent;
	class UTESRace;
	class UVCharacterAppearancePairingComponent;
	class UVCharacterBodyPairingComponent;
	class UVCharacterPhenotypeData;
	class UVDockingPairingComponent;
	class UVHumanoidHeadComponent;

	using FOnAppearanceRefreshedEndDelegate = TBaseDynamicMulticastDelegate<FNotThreadSafeDelegateMode, void>;
	using FOnCharacterRaceChangedDelegate = TBaseDynamicMulticastDelegate<FNotThreadSafeDelegateMode, void>;
	using FOnCharacterSexChangedDelegate = TBaseDynamicMulticastDelegate<FNotThreadSafeDelegateMode, void>;

	class AVPairedCharacter :
		public AVPairedPawn
	{
	public:
		UE_DEFINE_UOBJECT(AVPairedCharacter, AVPairedPawn, "Altar", "VPairedCharacter");

		// override
		virtual ~AVPairedCharacter();  // 000

		// add
		virtual void                    RefreshAppearance(const EVCharacterRefreshSelector a_selector);                                                              //
		virtual TArray<UMeshComponent*> GetPOVVisibleMeshComponents();                                                                                               //
		virtual void                    AttachToHorse(const AVPairedCreature* a_horse);                                                                              //
		virtual void                    OnBodyPartPropertiesChanged(const EBipedModularBodySlot a_slot, const FVCharacterBodyPartProperties* a_properties);          //
		virtual void                    ApplyBodyPartPropertiesToChildActor(const EBipedModularBodySlot a_slot, const FVCharacterBodyPartProperties* a_properties);  //

		// members
		const FVector                                              furnitureToNavmeshSnapExtents;          // E30
		const FName                                                horseRidingSocketName;                  // E48
		const FName                                                horseDismountSocketName;                // E50
		TMulticastDelegate<void(bool), FDefaultDelegateUserPolicy> onDockingTransitionStarted;             // E58
		TMulticastDelegate<void(bool), FDefaultDelegateUserPolicy> onDockingTransitionEnded;               // E70
		FName                                                      dockWarpTargetName;                     // E88
		UTESRace*                                                  race;                                   // E90
		ECharacterSex                                              sex;                                    // E98
		EVVoiceType                                                voiceType;                              // E99
		EVCharacterRefreshSelector                                 inFlightSelector;                       // E9A
		TSharedPtr<FStreamableHandle>                              refreshAppearanceHandle;                // EA0
		bool                                                       isInDockingProcess;                     // EB0
		FOnCharacterRaceChangedDelegate                            onCharacterRaceChanged;                 // EB8
		FOnCharacterSexChangedDelegate                             onCharacterSexChanged;                  // EC8
		FOnAppearanceRefreshedEndDelegate                          onAppearanceRefreshedEnd;               // ED8
		bool                                                       useDefaultRaceAndSexPreset;             // EE8
		UVCharacterPhenotypeData*                                  phenotypeData;                          // EF0
		TObjectPtr<UVHumanoidHeadComponent>                        humanoidHeadComponent;                  // EF8
		TObjectPtr<UChildActorComponent>                           headwearChildActorComponent;            // F00
		TObjectPtr<UChildActorComponent>                           upperBodyChildActorComponent;           // F08
		TObjectPtr<UChildActorComponent>                           lowerBodyChildActorComponent;           // F10
		TObjectPtr<UChildActorComponent>                           handsChildActorComponent;               // F18
		TObjectPtr<UChildActorComponent>                           feetChildActorComponent;                // F20
		TObjectPtr<UChildActorComponent>                           amuletChildActorComponent;              // F28
		TObjectPtr<UChildActorComponent>                           rightRingChildActorComponent;           // F30
		TObjectPtr<UChildActorComponent>                           leftRingChildActorComponent;            // F38
		TObjectPtr<UVCharacterBodyPairingComponent>                characterBodyPairingComponent;          // F40
		TObjectPtr<UVDockingPairingComponent>                      dockingPairingComponent;                // F48
		TObjectPtr<UMotionWarpingComponent>                        humanoidMotionWarpingComponent;         // F50
		TObjectPtr<UVCharacterAppearancePairingComponent>          characterAppearancePairingComponent;    // F58
		float                                                      emotionBlendValueMultiplier;            // F60
		bool                                                       hasUndockingQueued;                     // F64
		TMap<EBipedModularBodySlot, FInitialEquipmentInfo>         initialEquipmentMap;                    // F68
		FTimerHandle                                               refreshMergedMeshTimerHandle;           // FB8
		FDelegateHandle                                            weaponDrawnStateChangedDelegateHandle;  // FC0
		TScriptDelegate<FNotThreadSafeDelegateMode>                facialAnimationMontageEndedHandle;      // FC8
		float                                                      refreshMergeMeshDelay;                  // FD8
	};
	static_assert(sizeof(AVPairedCharacter) == 0xFE0);
}
