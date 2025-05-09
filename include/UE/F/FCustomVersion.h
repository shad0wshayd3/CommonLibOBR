#pragma once

#include "UE/F/FGuid.h"
#include "UE/F/FName.h"
#include "UE/T/TArray.h"

namespace UE
{
	class FCustomVersion;

	using FCustomVersionArray = TArray<FCustomVersion>;

	using CustomVersionValidatorFunc = bool (*)(const FCustomVersion& a_version, const FCustomVersionArray& a_allVersions, const wchar_t* a_debugContext);

	class FCustomVersion
	{
	public:
		// members
		FGuid                      key;
		std::int32_t               version;
		std::int32_t               referenceCount;
		CustomVersionValidatorFunc validator;
		mutable FName              friendlyName;
	};
	static_assert(sizeof(FCustomVersion) == 0x28);
}
