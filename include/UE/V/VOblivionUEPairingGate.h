#pragma once

#include "UE/F/FGenericPlatformProcess.h"
#include "UE/I/IPairingGate.h"
#include "UE/T/TAllocatorFixedSizeFreeList.h"
#include "UE/T/TArray.h"
#include "UE/T/TUniquePtr.h"
#include "UE/V/VPairingFlowManager.h"

namespace UE
{
	class VPairingEntry;

	class VOblivionUEPairingGate :
		public IPairingGate
	{
	public:
		// override
		virtual ~VOblivionUEPairingGate();                                                                                              // 00
		virtual void                ReleaseAsyncFlow(std::uint32_t a_flowHash) override;                                                // 01
		virtual bool                IsFlowContainedInBuffer(std::uint32_t a_flowHash) override;                                         // 02
		virtual void                CleanUp() override;                                                                                 // 03
		virtual VPairingEntry*      CreatePairingEntry(void* a_originalItem) override;                                                  // 04
		virtual void                ConditionalDestroyPairingEntry(VPairingEntry* a_pairingEntry) override;                             // 05
		virtual void                BeginSendingSession(std::uint64_t a_frameNumber) override;                                          // 06
		virtual void                EndSendingSession(std::uint64_t a_frameNumber, std::uint32_t a_type) override;                      // 07
		virtual bool                IsSendingSessionActive(std::uint32_t a_flowHash) override;                                          // 08
		virtual bool                IsSendingSessionActive() override;                                                                  // 09
		virtual void                ReplicateUnpairing(VPairingEntry** a_pairingEntryPtr) override;                                     // 0A
		virtual std::uint32_t       MakeAsyncPairingFlowHash(const char* a_string) override;                                            // 0B
		virtual void                BeginAsyncPairingFlow(std::uint32_t a_flowHash, std::uint32_t a_asyncFlowDefaultBuffers) override;  // 0C
		virtual void                EndAsyncPairingFlow() override;                                                                     // 0D
		virtual EVExecHandlerStatus ExecuteHandlers(std::uint32_t a_requestedFlowHash) override;                                        // 0E
		virtual void                SendSyncSignal() override;                                                                          // 0F
		virtual void                WaitForSyncSignal() override;                                                                       // 10
		virtual bool                IsCurrentFlowAsync() override;                                                                      // 11
		virtual void                CheckHandlerSentOnCorrectThread() override;                                                         // 12
		virtual void                SetUseTimelimit(bool a_isLimited) override;                                                         // 13
		virtual bool                GetUseTimeLimit() override;                                                                         // 14
		virtual bool                IsFlowFilledAboveThreshold(std::uint32_t a_hash, float a_thresholdRatio) override;                  // 15
		virtual void                SetOriginalGameThreadId(std::uint32_t a_originalGameThreadId) override;                             // 16
		virtual void                EndReverseFlowExecution() override;                                                                 // 17
		virtual bool                SkipHandlerInAsyncFlow(std::uint32_t a_requestedFlowHash) override;                                 // 18
		virtual void*               AllocateHandler(std::uint64_t a_newHandlerClassSize) override;                                      // 19
		virtual void                SignalSendingHandler(std::uint64_t a_frameNumber, const char* a_handlerName) override;              // 1A
		virtual void                DebugHelper(std::uint64_t, void*, const char*, std::uint64_t) override;                             // 1B

		static VOblivionUEPairingGate* GetSingleton()
		{
			using func_t = decltype(&VOblivionUEPairingGate::GetSingleton);
			static REL::Relocation<func_t> func{ ID::VOblivionUEPairingGate::GetSingleton };
			return func();
		}

		// members
		bool                                            asyncTimeLimited;                // 18
		std::uint32_t                                   usedPairingEntryCount;           // 1C
		std::uint32_t                                   allocatedPairingEntryCount;      // 20
		std::uint32_t                                   allocatedPairingEntryTotalSize;  // 24
		TAllocatorFixedSizeFreeList<24, 256>            pairingEntriesFreeList;          // 28
		FCriticalSection                                pairingListCriticalSection;      // 38
		TUniquePtr<FGenericPlatformProcess::FSemaphore> gamesSyncSemaphore;              // 60
		TArray<VPairingEntry*>                          currentPairingEntries;           // 68
		VPairingFlowManager                             flowManager;                     // 78
	};
	static_assert(sizeof(VOblivionUEPairingGate) == 0x128);
}
