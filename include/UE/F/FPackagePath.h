#pragma once

#include "UE/E/EPackageExtension.h"
#include "UE/F/FName.h"

namespace UE
{
	class FPackagePath
	{
	public:
		FPackagePath() = default;

		// members
		FName                     packageName;                                        // 00
		mutable EPackageExtension headerExtension{ EPackageExtension::Unspecified };  // 08
	};
	static_assert(sizeof(FPackagePath) == 0x0C);
}
