#pragma once

#include "UE/F/FName.h"

namespace UE
{
	class FTopLevelAssetPath
	{
	public:
		FName GetPackageName() const
		{
			return packageName;
		}

		FName GetAssetName() const
		{
			return assetName;
		}

		bool IsNull() const
		{
			return packageName.IsNone();
		}

		// members
		FName packageName;
		FName assetName;
	};
}
