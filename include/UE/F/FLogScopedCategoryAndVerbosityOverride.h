#pragma once

#include "UE/E/ELogVerbosity.h"
#include "UE/F/FName.h"

namespace UE
{
	class FLogScopedCategoryAndVerbosityOverride
	{
	public:
		class FOverride
		{
		public:
			FOverride() = default;

			FOverride(FName a_category, ELogVerbosity a_verbosity) :
				verbosity(a_verbosity), category(a_category)
			{}

			// members
			ELogVerbosity verbosity{ ELogVerbosity::Log };  // 00
			FName         category;                         // 04
		};
		static_assert(sizeof(FOverride) == 0xC);

		static FOverride* GetTLSCurrent()
		{
			using func_t = decltype(&FLogScopedCategoryAndVerbosityOverride::GetTLSCurrent);
			static REL::Relocation<func_t> func{ ID::FLogScopedCategoryAndVerbosityOverride::GetTLSCurrent };
			return func();
		}

	private:
		FOverride m_backup;  // 00
	};
	static_assert(sizeof(FLogScopedCategoryAndVerbosityOverride) == 0xC);
}
