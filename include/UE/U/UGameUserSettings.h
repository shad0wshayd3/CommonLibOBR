#pragma once

#include "UE/F/FIntPoint.h"
#include "UE/F/FQualityLevels.h"
#include "UE/T/TBaseDynamicMulticastDelegate.h"
#include "UE/T/TDelegate.h"
#include "UE/U/UObject.h"

namespace UE
{
	using FOnGameUserSettingsUINeedsUpdate = TBaseDynamicMulticastDelegate<FNotThreadSafeDelegateMode, void>;
	using FUpdateGameUserSettingsFileFromCloud = TDelegate<bool(const FString&)>;
	using FUpdateCloudDataFromGameUserSettings = TDelegate<bool(const FString&)>;

	class UGameUserSettings :
		public UObject
	{
	public:
		UE_DEFINE_UOBJECT(UGameUserSettings, UObject, "Engine", "GameUserSettings");

		// override
		virtual ~UGameUserSettings();  // 000

		// add
		virtual void      ApplySettings(bool a_cmd);                                                                                    // 057
		virtual void      ApplyNonResolutionSettings();                                                                                 // 058
		virtual bool      IsDynamicResolutionEnabled();                                                                                 // 059
		virtual void      ConfirmVideoMode();                                                                                           // 05A
		virtual void      SetOverallScalabilityLevel(std::int32_t a_value);                                                             // 05B
		virtual int       GetOverallScalabilityLevel();                                                                                 // 05C
		virtual bool      IsDirty();                                                                                                    // 05D
		virtual void      ValidateSettings();                                                                                           // 05E
		virtual void      LoadSettings(bool a_force);                                                                                   // 05F
		virtual void      SaveSettings();                                                                                               // 060
		virtual void      ResetToCurrentSettings();                                                                                     // 061
		virtual void      SetWindowPosition(std::int32_t a_x, std::int32_t a_y);                                                        // 062
		virtual FIntPoint GetWindowPosition();                                                                                          // 063
		virtual void      SetToDefaults();                                                                                              // 064
		virtual float     GetDefaultResolutionScale();                                                                                  // 065
		virtual float     GetRecommendedResolutionScale();                                                                              // 066
		virtual void      RunHardwareBenchmark(std::int32_t a_scale = 10, float a_cpuMultiplier = 1.0F, float a_gpuMultiplier = 1.0F);  // 067
		virtual void      ApplyHardwareBenchmarkResults();                                                                              // 068
		virtual bool      SupportsHDRDisplayOutput();                                                                                   // 069
		virtual bool      IsVersionValid();                                                                                             // 06A
		virtual void      UpdateVersion();                                                                                              // 06B
		virtual float     GetEffectiveFrameRateLimit();                                                                                 // 06C

		// members
		bool                                 useVSync;                               // 028
		bool                                 useDynamicResolution;                   // 029
		Scalability::FQualityLevels          scalabilityQuality;                     // 030
		std::uint32_t                        resolutionSizeX;                        // 088
		std::uint32_t                        resolutionSizeY;                        // 08C
		std::uint32_t                        lastUserConfirmedResolutionSizeX;       // 090
		std::uint32_t                        lastUserConfirmedResolutionSizeY;       // 094
		std::int32_t                         windowPosX;                             // 098
		std::int32_t                         windowPosY;                             // 09C
		std::int32_t                         fullscreenMode;                         // 0A0
		std::int32_t                         lastConfirmedFullscreenMode;            // 0A4
		std::int32_t                         preferredFullscreenMode;                // 0A8
		std::uint32_t                        version;                                // 0AC
		std::int32_t                         audioQualityLevel;                      // 0B0
		std::int32_t                         lastConfirmedAudioQualityLevel;         // 0B4
		float                                frameRateLimit;                         // 0B8
		float                                minResolutionScale;                     // 0BC
		std::int32_t                         desiredScreenWidth;                     // 0C0
		bool                                 useDesiredScreenHeight;                 // 0C4
		std::int32_t                         desiredScreenHeight;                    // 0C8
		std::int32_t                         lastUserConfirmedDesiredScreenWidth;    // 0CC
		std::int32_t                         lastUserConfirmedDesiredScreenHeight;   // 0D0
		float                                lastRecommendedScreenWidth;             // 0D4
		float                                lastRecommendedScreenHeight;            // 0D8
		float                                lastCPUBenchmarkResult;                 // 0DC
		float                                lastGPUBenchmarkResult;                 // 0E0
		TArray<float>                        lastCPUBenchmarkSteps;                  // 0E8
		TArray<float>                        lastGPUBenchmarkSteps;                  // 0F8
		float                                lastGPUBenchmarkMultiplier;             // 108
		bool                                 useHDRDisplayOutput;                    // 10C
		std::int32_t                         hdrDisplayOutputNits;                   // 110
		FUpdateGameUserSettingsFileFromCloud onUpdateGameUserSettingsFileFromCloud;  // 118
		FUpdateCloudDataFromGameUserSettings onUpdateCloudDataFromGameUserSettings;  // 128
		FOnGameUserSettingsUINeedsUpdate     onGameUserSettingsUINeedsUpdate;        // 138
	};
	static_assert(sizeof(UGameUserSettings) == 0x148);
}
