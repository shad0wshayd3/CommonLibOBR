#pragma once

#include "UE/F/FExec.h"
#include "UE/F/FURL.h"
#include "UE/T/TSharedPtr.h"
#include "UE/U/UObject.h"

namespace UE
{
	namespace EBrowseReturnVal
	{
		enum class Type : std::int32_t;
	}

	namespace ENetworkFailure
	{
		enum class Type : std::int32_t;
	}

	namespace ENetworkLagState
	{
		enum class Type : std::int32_t;
	}

	namespace ERHIFeatureLevel
	{
		enum class Type : std::int32_t;
	}

	namespace ETravelFailure
	{
		enum class Type : std::int32_t;
	}

	enum class EGarbageCollectionType : std::int8_t;

	class AActor;
	class FAnalyticsEventAttribute;
	class FColor;
	class FWorldContext;
	class IEngineLoop;
	class SViewport;
	class UGameViewportClient;
	class UNetConnection;
	class UNetDriver;
	class UPendingNetGame;
	class UWorld;

	class UEngine :
		public UObject,
		public FExec
	{
	public:
		UE_DEFINE_UOBJECT("Engine", "Engine");

		// override
		virtual ~UEngine();  // 00

		// add
		virtual void                   WorldAdded(UWorld*);                                                                   // 57
		virtual void                   WorldDestroyed(UWorld*);                                                               // 58
		virtual bool                   IsInitialized();                                                                       // 59
		virtual ERHIFeatureLevel::Type GetDefaultWorldFeatureLevel();                                                         // 5A
		virtual void                   Init(IEngineLoop*);                                                                    // 5B
		virtual void                   Start();                                                                               // 5C
		virtual void                   PreExit();                                                                             // 5D
		virtual void                   ReleaseAudioDeviceManager();                                                           // 5E
		virtual void                   Tick(float, bool);                                                                     // 5F
		virtual void                   UpdateTimeAndHandleMaxTickRate();                                                      // 60
		virtual long double            CorrectNegativeTimeDelta(long double);                                                 // 61
		virtual float                  GetMaxTickRate(float, bool);                                                           // 62
		virtual float                  GetMaxFPS();                                                                           // 63
		virtual void                   SetMaxFPS(const float);                                                                // 64
		virtual void                   UpdateRunningAverageDeltaTime(float, bool);                                            // 65
		virtual bool                   IsAllowedFramerateSmoothing();                                                         // 66
		virtual bool                   IsRenderingSuspended();                                                                // 67
		virtual void                   OnLostFocusPause(bool);                                                                // 68
		virtual bool                   ShouldThrottleCPUUsage();                                                              // 69
		virtual bool                   IsControllerIdUsingPlatformUserId();                                                   // 6A
		virtual bool                   ShouldDrawBrushWireframe(AActor*);                                                     // 6B
		virtual bool                   GetMapBuildCancelled();                                                                // 6C
		virtual void                   SetMapBuildCancelled(bool);                                                            // 6D
		virtual bool                   IsPropertyColorationColorFeatureActivated();                                           // 6E
		virtual bool                   GetPropertyColorationColor(UObject*, FColor*);                                         // 6F
		virtual bool                   AllowSelectTranslucent();                                                              // 70
		virtual bool                   OnlyLoadEditorVisibleLevelsInPIE();                                                    // 71
		virtual bool                   PreferToStreamLevelsInPIE();                                                           // 72
		virtual int                    GetSpriteCategoryIndex(const FName*);                                                  // 73
		virtual float                  GetTimeBetweenGarbageCollectionPasses(bool);                                           // 74
		virtual void                   StartFPSChart(const FString*, bool);                                                   // 75
		virtual void                   StopFPSChart(const FString*);                                                          // 76
		virtual void                   ProcessToggleFreezeCommand(UWorld*);                                                   // 77
		virtual void                   ProcessToggleFreezeStreamingCommand(UWorld*);                                          // 78
		virtual EGarbageCollectionType ShouldForceGarbageCollection();                                                        // 79
		virtual bool                   IsSplitScreen(UWorld*);                                                                // 7A
		virtual bool                   HasMultipleLocalPlayers(UWorld*);                                                      // 7B
		virtual bool                   IsSettingUpPlayWorld();                                                                // 7C
		virtual TSharedPtr<SViewport>* GetGameViewportWidget(TSharedPtr<SViewport>* result);                                  // 7D
		virtual void                   FocusNextPIEWorld(UWorld*, bool);                                                      // 7E
		virtual void                   ResetPIEAudioSetting(UWorld*);                                                         // 7F
		virtual UGameViewportClient*   GetNextPIEViewport(UGameViewportClient*);                                              // 80
		virtual void                   RemapGamepadControllerIdForPIE(UGameViewportClient*, int*);                            // 81
		virtual void                   NotifyToolsOfObjectReplacement(const TMap<UObject*, UObject*>*);                       // 82
		virtual bool                   UseSound();                                                                            // 83
		virtual UWorld*                CreatePIEWorldByDuplication(FWorldContext*, UWorld*, FString*);                        // 84
		virtual void                   PostCreatePIEWorld(UWorld*);                                                           // 85
		virtual bool                   Experimental_ShouldPreDuplicateMap(const FName);                                       // 86
		virtual void                   InitializeAudioDeviceManager();                                                        // 87
		virtual bool                   InitializeHMDDevice();                                                                 // 88
		virtual bool                   InitializeEyeTrackingDevice();                                                         // 89
		virtual void                   RecordHMDAnalytics();                                                                  // 8A
		virtual void                   InitializeObjectReferences();                                                          // 8B
		virtual void                   InitializePortalServices();                                                            // 8C
		virtual void                   InitializeRunningAverageDeltaTime();                                                   // 8D
		virtual void                   SpawnServerActors(UWorld*);                                                            // 8E
		virtual void                   HandleNetworkFailure(UWorld*, UNetDriver*, ENetworkFailure::Type, const FString*);     // 8F
		virtual void                   HandleTravelFailure(UWorld*, ETravelFailure::Type, const FString*);                    // 90
		virtual void                   HandleNetworkLagStateChanged(UWorld*, UNetDriver*, ENetworkLagState::Type);            // 91
		virtual bool                   NetworkRemapPath(UPendingNetGame*, FString*, bool);                                    // 92
		virtual bool                   NetworkRemapPath(UNetConnection*, FString*, bool);                                     // 93
		virtual bool                   HandleOpenCommand(const wchar_t*, FOutputDevice*, UWorld*);                            // 94
		virtual bool                   HandleTravelCommand(const wchar_t*, FOutputDevice*, UWorld*);                          // 95
		virtual bool                   HandleStreamMapCommand(const wchar_t*, FOutputDevice*, UWorld*);                       // 96
		virtual bool                   HandleServerTravelCommand(const wchar_t*, FOutputDevice*, UWorld*);                    // 97
		virtual bool                   HandleDisconnectCommand(const wchar_t*, FOutputDevice*, UWorld*);                      // 98
		virtual bool                   HandleReconnectCommand(const wchar_t*, FOutputDevice*, UWorld*);                       // 99
		virtual EBrowseReturnVal::Type Browse(FWorldContext*, FURL, FString*);                                                // 9A
		virtual void                   TickWorldTravel(FWorldContext*, float);                                                // 9B
		virtual bool                   LoadMap(FWorldContext*, FURL, UPendingNetGame*, FString*);                             // 9C
		virtual void                   RedrawViewports(bool);                                                                 // 9D
		virtual void                   TriggerStreamingDataRebuild();                                                         // 9E
		virtual void                   LoadMapRedrawViewports();                                                              // 9F
		virtual void                   CancelAllPending();                                                                    // A0
		virtual void                   CancelPending(UNetDriver*);                                                            // A1
		virtual void                   CancelPending(FWorldContext*);                                                         // A2
		virtual void                   CancelPending(UWorld*, UPendingNetGame*);                                              // A3
		virtual bool                   WorldIsPIEInNewViewport(UWorld*);                                                      // A4
		virtual void                   CheckAndHandleStaleWorldObjectReferences(FWorldContext*);                              // A5
		virtual void                   DestroyWorldContext(UWorld*);                                                          // A6
		virtual bool                   AreEditorAnalyticsEnabled();                                                           // A7
		virtual void                   CreateStartupAnalyticsAttributes(TArray<FAnalyticsEventAttribute>*);                   // A8
		virtual bool                   IsAutosaving();                                                                        // A9
		virtual bool                   ShouldDoAsyncEndOfFrameTasks();                                                        // AA
		virtual void                   MovePendingLevel(FWorldContext*);                                                      // AB
		virtual bool                   ShouldShutdownWorldNetDriver();                                                        // AC
		virtual void                   HandleBrowseToDefaultMapFailure(FWorldContext*, const FString*, const FString*);       // AD
		virtual void                   HandleNetworkFailure_NotifyGameInstance(UWorld*, UNetDriver*, ENetworkFailure::Type);  // AE
		virtual void                   HandleTravelFailure_NotifyGameInstance(UWorld*, ETravelFailure::Type);                 // AF

		static UEngine* GetSingleton()
		{
			using func_t = decltype(&UEngine::GetSingleton);
			static REL::Relocation<UEngine**> singleton{ ID::UEngine::GetSingleton };
			return *singleton;
		}

		UWorld* GetCurrentPlayWorld(UWorld* a_possiblePlayWorld)
		{
			using func_t = decltype(&UEngine::GetCurrentPlayWorld);
			static REL::Relocation<func_t> func{ ID::UEngine::GetCurrentPlayWorld };
			return func(this, a_possiblePlayWorld);
		}

		// members
		std::byte unk30[0x1048];  // 30
	};
	static_assert(sizeof(UEngine) == 0x1078);
}
