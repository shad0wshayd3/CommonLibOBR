#pragma once

namespace UE
{
	class FCriticalSection
	{
	public:
		FCriticalSection()
		{
			REX::W32::InitializeCriticalSection(&criticalSection);
			REX::W32::SetCriticalSectionSpinCount(&criticalSection, 4000);
		}

		~FCriticalSection()
		{
			REX::W32::DeleteCriticalSection(&criticalSection);
		}

		void Lock()
		{
			REX::W32::EnterCriticalSection(&criticalSection);
		}

		bool TryLock()
		{
			return REX::W32::TryEnterCriticalSection(&criticalSection);
		}

		void Unlock()
		{
			REX::W32::LeaveCriticalSection(&criticalSection);
		}

		// members
		REX::W32::CRITICAL_SECTION criticalSection;
	};
	static_assert(sizeof(FCriticalSection) == 0x28);
}
