#pragma once

#include "UE/E/EAutoReceiveInput.h"
#include "UE/E/ENetDormancy.h"
#include "UE/E/ENetRole.h"
#include "UE/E/EPhysicsReplicationMode.h"
#include "UE/E/ESpawnActorCollisionHandlingMethod.h"
#include "UE/F/FActorTickFunction.h"
#include "UE/F/FRenderCommandFence.h"
#include "UE/F/FRepAttachment.h"
#include "UE/F/FRepMovement.h"
#include "UE/F/FTimerHandle.h"
#include "UE/T/TObjectPtr.h"
#include "UE/T/TWeakObjectPtr.h"
#include "UE/U/UObject.h"

namespace UE::Net
{
	class FReplicatedComponentInfo;
}

namespace UE
{
	class APawn;
	class UActorComponent;
	class UChildActorComponent;
	class UInputComponent;
	class USceneComponent;

	enum class EActorUpdateOverlapsMethod : std::uint8_t
	{
		UseConfigDefault,
		AlwaysUpdate,
		OnlyUpdateMovable,
		NeverUpdate
	};

	enum class ESpawnActorScaleMethod : std::uint8_t
	{
		OverrideRootScale,
		MultiplyWithRoot,
		SelectDefaultAtRuntime,
	};

	class AActor :
		public UObject
	{
	public:
		UE_DEFINE_OBJECT("/Script/Engine", "Actor");

		enum class EActorBeginPlayState : std::uint8_t
		{
			HasNotBegunPlay,
			BeginningPlay,
			HasBegunPlay,
		};

		// override
		virtual ~AActor();  // 00

		// members
		FActorTickFunction                    primaryActorTick;
		std::uint8_t                          netTemporary: 1;
		std::uint8_t                          netStartup: 1;
		std::uint8_t                          onlyRelevantToOwner: 1;
		std::uint8_t                          alwaysRelevant: 1;
		std::uint8_t                          replicateMovement: 1;
		std::uint8_t                          callPreReplication: 1;
		std::uint8_t                          callPreReplicationForReplay: 1;
		std::uint8_t                          hidden: 1;
		std::uint8_t                          tearOff: 1;
		std::uint8_t                          forceNetAddressable: 1;
		std::uint8_t                          exchangedRoles: 1;
		std::uint8_t                          netLoadOnClient: 1;
		std::uint8_t                          netUseOwnerRelevancy: 1;
		std::uint8_t                          relevantForNetworkReplays: 1;
		std::uint8_t                          relevantForLevelBounds: 1;
		std::uint8_t                          replayRewindable: 1;
		std::uint8_t                          allowTickBeforeBeginPlay: 1;
		std::uint8_t                          autoDestroyWhenFinished: 1;
		std::uint8_t                          canBeDamaged: 1;
		std::uint8_t                          blockInput: 1;
		std::uint8_t                          collideWhenPlacing: 1;
		std::uint8_t                          findCameraComponentWhenViewTarget: 1;
		std::uint8_t                          generateOverlapEventsDuringLevelStreaming: 1;
		std::uint8_t                          ignoresOriginShifting: 1;
		std::uint8_t                          enableAutoLODGeneration: 1;
		std::uint8_t                          isEditorOnlyActor: 1;
		std::uint8_t                          actorSeamlessTraveled: 1;
		std::uint8_t                          replicates: 1;
		std::uint8_t                          canBeInCluster: 1;
		std::uint8_t                          allowReceiveTickEventOnDedicatedServer: 1;
		std::uint8_t                          netCheckedInitialPhysicsState: 1;
		std::uint8_t                          replicateUsingRegisteredSubObjectList: 1;
		std::uint8_t                          hasFinishedSpawning: 1;
		std::uint8_t                          actorInitialized: 1;
		std::uint8_t                          actorBeginningPlayFromLevelStreaming: 1;
		std::uint8_t                          tickFunctionsRegistered: 1;
		std::uint8_t                          hasDeferredComponentRegistration: 1;
		std::uint8_t                          runningUserConstructionScript: 1;
		std::uint8_t                          hasRegisteredAllComponents: 1;
		std::uint8_t                          actorEnableCollision: 1;
		std::uint8_t                          actorIsBeingDestroyed: 1;
		std::uint8_t                          actorWantsDestroyDuringBeginPlay: 1;
		EActorBeginPlayState                  actorHasBegunPlay: 2;
		std::uint8_t                          actorIsBeingConstructed: 1;
		std::uint8_t                          asyncPhysicsTickEnabled: 1;
		EActorUpdateOverlapsMethod            updateOverlapsMethodDuringLevelStreaming;
		EActorUpdateOverlapsMethod            defaultUpdateOverlapsMethodDuringLevelStreaming;
		float                                 initialLifeSpan;
		float                                 customTimeDilation;
		TEnumAsByte<ENetRole>                 remoteRole;
		std::int32_t                          rayTracingGroupId;
		FRepAttachment                        attachmentReplication;
		FRepMovement                          replicatedMovement;
		TObjectPtr<AActor>                    owner;
		FName                                 netDriverName;
		TEnumAsByte<ENetRole>                 role;
		TEnumAsByte<ENetDormancy>             netDormancy;
		ESpawnActorCollisionHandlingMethod    spawnCollisionHandlingMethod;
		TEnumAsByte<EAutoReceiveInput>        autoReceiveInput;
		std::int32_t                          inputPriority;
		float                                 creationTime;
		TObjectPtr<UInputComponent>           inputComponent;
		float                                 netCullDistanceSquared;
		std::int32_t                          netTag;
		float                                 netUpdateFrequency;
		float                                 minNetUpdateFrequency;
		float                                 netPriority;
		EPhysicsReplicationMode               physicsReplicationMode;
		float                                 lastRenderTime;
		TObjectPtr<APawn>                     instigator;
		TArray<TObjectPtr<AActor>>            children;
		TObjectPtr<USceneComponent>           rootComponent;
		FTimerHandle                          timerHandle_LifeSpanExpired;
		TArray<FName>                         layers;
		TWeakObjectPtr<UChildActorComponent>  parentComponent;
		TArray<FName>                         tags;
		std::uint8_t                          onTakeAnyDamage;             // - FTakeAnyDamageSignature
		std::uint8_t                          onTakePointDamage;           // - FTakePointDamageSignature
		std::uint8_t                          onTakeRadialDamage;          // - FTakeRadialDamageSignature
		std::uint8_t                          onActorBeginOverlap;         // - FActorBeginOverlapSignature
		std::uint8_t                          onActorEndOverlap;           // - FActorEndOverlapSignature
		std::uint8_t                          onBeginCursorOver;           // - FActorBeginCursorOverSignature
		std::uint8_t                          onEndCursorOver;             // - FActorEndCursorOverSignature
		std::uint8_t                          onClicked;                   // - FActorOnClickedSignature
		std::uint8_t                          onReleased;                  // - FActorOnReleasedSignature
		std::uint8_t                          onInputTouchBegin;           // - FActorOnInputTouchBeginSignature
		std::uint8_t                          onInputTouchEnd;             // - FActorOnInputTouchEndSignature
		std::uint8_t                          onInputTouchEnter;           // - FActorBeginTouchOverSignature
		std::uint8_t                          onInputTouchLeave;           // - FActorEndTouchOverSignature
		std::uint8_t                          onActorHit;                  // - FActorHitSignature
		std::uint8_t                          onDestroyed;                 // - FActorDestroyedSignature
		std::uint8_t                          onEndPlay;                   // - FActorEndPlaySignature
		std::byte                             replicatedSubObjects[0x10];  // - Net::FSubObjectRegistry
		TArray<Net::FReplicatedComponentInfo> replicatedComponentsInfo;
		TArray<UActorComponent*>              replicatedComponents;
		TSet<TObjectPtr<UActorComponent>>     ownedComponents;
		TArray<TObjectPtr<UActorComponent>>   instanceComponents;
		TArray<TObjectPtr<UActorComponent>>   blueprintCreatedComponents;
		FRenderCommandFence                   detachFence;
	};
	static_assert(sizeof(AActor) == 0x298);
}
