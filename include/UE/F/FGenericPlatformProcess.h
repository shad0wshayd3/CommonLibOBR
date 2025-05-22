#pragma once

namespace UE
{
	class FGenericPlatformProcess
	{
	public:
		class ApplicationSettingsContext
		{
		public:
			enum class Context : std::int8_t
			{
				kLocalUser,
				kRoamingUser,
				kApplicationSpecific
			};

			// members
			Context location;  // 00
			bool    isEpic;    // 01
		};
		static_assert(sizeof(ApplicationSettingsContext) == 0x02);

		class FSemaphore
		{
		public:
			// add
			virtual void Lock() = 0;                                      // 00
			virtual bool TryLock(std::uint64_t a_nanosecondsToWait) = 0;  // 08
			virtual void Unlock() = 0;                                    // 10
			virtual ~FSemaphore();                                        // 18

			// members
			wchar_t name[128];  // 08
		};
		static_assert(sizeof(FSemaphore) == 0x108);
	};
	static_assert(std::is_empty_v<FGenericPlatformProcess>);
}
