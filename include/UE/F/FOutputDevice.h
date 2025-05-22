#pragma once

#include "UE/E/ELogVerbosity.h"
#include "UE/F/FLogScopedCategoryAndVerbosityOverride.h"
#include "UE/F/FText.h"

namespace UE
{
	class FArchive;
	class FLogRecord;
	class FName;

	class FOutputDevice
	{
	public:
		// add
		virtual ~FOutputDevice() = default;  // 00

		// add
		virtual void Serialize(const wchar_t* a_value, ELogVerbosity a_verbosity, const FName& a_category) = 0;                   // 01
		virtual void Serialize(const wchar_t* a_value, ELogVerbosity a_verbosity, const FName& a_category, const double a_time);  // 02
		virtual void SerializeRecord(const FLogRecord& a_record);                                                                 // 03
		virtual void Flush();                                                                                                     // 04
		virtual void TearDown();                                                                                                  // 05
		virtual void Dump(FArchive& a_archive);                                                                                   // 06
		virtual bool IsMemoryOnly() const;                                                                                        // 07
		virtual bool CanBeUsedOnAnyThread() const;                                                                                // 08
		virtual bool CanBeUsedOnMultipleThreads() const;                                                                          // 09
		virtual bool CanBeUsedOnPanicThread() const;                                                                              // 10

		void Log(const wchar_t* a_string)
		{
			const auto tls = FLogScopedCategoryAndVerbosityOverride::GetTLSCurrent();
			Serialize(a_string, tls->verbosity, tls->category);
		}

		void Log(const FString& a_string)
		{
			const auto tls = FLogScopedCategoryAndVerbosityOverride::GetTLSCurrent();
			Serialize(*a_string, tls->verbosity, tls->category);
		}

		void Log(const FText& a_text)
		{
			const auto tls = FLogScopedCategoryAndVerbosityOverride::GetTLSCurrent();
			Serialize(*a_text.ToString(), tls->verbosity, tls->category);
		}

		void Log(const ELogVerbosity a_verbosity, const wchar_t* a_string)
		{
			const auto tls = FLogScopedCategoryAndVerbosityOverride::GetTLSCurrent();
			Serialize(a_string, a_verbosity, tls->category);
		}

		void Log(const ELogVerbosity a_verbosity, const FString& a_string)
		{
			const auto tls = FLogScopedCategoryAndVerbosityOverride::GetTLSCurrent();
			Serialize(*a_string, a_verbosity, tls->category);
		}

		void Log(const ELogVerbosity a_verbosity, const FText& a_text)
		{
			const auto tls = FLogScopedCategoryAndVerbosityOverride::GetTLSCurrent();
			Serialize(*a_text.ToString(), a_verbosity, tls->category);
		}

		void Log(const FName& a_category, const ELogVerbosity a_verbosity, const wchar_t* a_string)
		{
			Serialize(a_string, a_verbosity, a_category);
		}

		void Log(const FName& a_category, const ELogVerbosity a_verbosity, const FString& a_string)
		{
			Serialize(*a_string, a_verbosity, a_category);
		}

		void Log(const FName& a_category, const ELogVerbosity a_verbosity, const FText& a_text)
		{
			Serialize(*a_text.ToString(), a_verbosity, a_category);
		}

		// members
		bool suppressEventTag;        // 008
		bool autoEmitLineTerminator;  // 009
	};
	static_assert(sizeof(FOutputDevice) == 0x010);
}
