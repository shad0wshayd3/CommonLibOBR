#pragma once

namespace UE
{
	class FWindowsRWLock
	{
	public:
		FWindowsRWLock(const FWindowsRWLock&) = delete;
		FWindowsRWLock& operator=(const FWindowsRWLock&) = delete;

		FWindowsRWLock([[maybe_unused]] std::uint32_t a_level = 0)
		{
			REX::W32::InitializeSRWLock(&mutex);
		}

		~FWindowsRWLock()
		{
			assert(!IsLocked());
		}

		void ReadLock()
		{
			REX::W32::AcquireSRWLockShared(&mutex);
		}

		void WriteLock()
		{
			REX::W32::AcquireSRWLockExclusive(&mutex);
		}

		bool TryReadLock()
		{
			return REX::W32::TryAcquireSRWLockShared(&mutex);
		}

		bool TryWriteLock()
		{
			return REX::W32::TryAcquireSRWLockExclusive(&mutex);
		}

		void ReadUnlock()
		{
			REX::W32::ReleaseSRWLockShared(&mutex);
		}

		void WriteUnlock()
		{
			REX::W32::ReleaseSRWLockExclusive(&mutex);
		}

		bool IsLocked()
		{
			if (REX::W32::TryAcquireSRWLockExclusive(&mutex)) {
				REX::W32::ReleaseSRWLockExclusive(&mutex);
				return false;
			} else {
				return true;
			}
		}

		// members
		REX::W32::SRWLOCK mutex;  // 00
	};

	using FRWLock = FWindowsRWLock;
}
