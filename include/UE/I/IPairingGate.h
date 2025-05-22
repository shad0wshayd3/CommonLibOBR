#pragma once

namespace UE
{
	enum class EVExecHandlerStatus : std::int8_t;
	class VPairingEntry;

	class IPairingGate
	{
	public:
		// add
		virtual ~IPairingGate();                                                                                                   // 00
		virtual void                ReleaseAsyncFlow(std::uint32_t a_flowHash) = 0;                                                // 01
		virtual bool                IsFlowContainedInBuffer(std::uint32_t a_flowHash) = 0;                                         // 02
		virtual void                CleanUp() = 0;                                                                                 // 03
		virtual VPairingEntry*      CreatePairingEntry(void* a_originalItem) = 0;                                                  // 04
		virtual void                ConditionalDestroyPairingEntry(VPairingEntry* a_pairingEntry) = 0;                             // 05
		virtual void                BeginSendingSession(std::uint64_t a_frameNumber) = 0;                                          // 06
		virtual void                EndSendingSession(std::uint64_t a_frameNumber, std::uint32_t a_type) = 0;                      // 07
		virtual bool                IsSendingSessionActive(std::uint32_t a_flowHash) = 0;                                          // 08
		virtual bool                IsSendingSessionActive() = 0;                                                                  // 09
		virtual void                ReplicateUnpairing(VPairingEntry** a_pairingEntryPtr) = 0;                                     // 0A
		virtual std::uint32_t       MakeAsyncPairingFlowHash(const char* a_string) = 0;                                            // 0B
		virtual void                BeginAsyncPairingFlow(std::uint32_t a_flowHash, std::uint32_t a_asyncFlowDefaultBuffers) = 0;  // 0C
		virtual void                EndAsyncPairingFlow() = 0;                                                                     // 0D
		virtual EVExecHandlerStatus ExecuteHandlers(std::uint32_t a_requestedFlowHash) = 0;                                        // 0E
		virtual void                SendSyncSignal() = 0;                                                                          // 0F
		virtual void                WaitForSyncSignal() = 0;                                                                       // 10
		virtual bool                IsCurrentFlowAsync() = 0;                                                                      // 11
		virtual void                CheckHandlerSentOnCorrectThread() = 0;                                                         // 12
		virtual void                SetUseTimelimit(bool a_isLimited) = 0;                                                         // 13
		virtual bool                GetUseTimeLimit() = 0;                                                                         // 14
		virtual bool                IsFlowFilledAboveThreshold(std::uint32_t a_hash, float a_thresholdRatio) = 0;                  // 15
		virtual void                SetOriginalGameThreadId(std::uint32_t a_originalGameThreadId) = 0;                             // 16
		virtual void                EndReverseFlowExecution() = 0;                                                                 // 17
		virtual bool                SkipHandlerInAsyncFlow(std::uint32_t a_requestedFlowHash) = 0;                                 // 18
		virtual void*               AllocateHandler(std::uint64_t a_newHandlerClassSize) = 0;                                      // 19
		virtual void                SignalSendingHandler(std::uint64_t a_frameNumber, const char* a_handlerName) = 0;              // 1A
		virtual void                DebugHelper(std::uint64_t, void*, const char*, std::uint64_t) = 0;                             // 1B

		// members
		std::byte existingAsyncFlows[0x10];  // 08 - std::map<std::string, std::uint32_t> [BAD!]
	};
	static_assert(sizeof(IPairingGate) == 0x18);
}
