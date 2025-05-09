#pragma once

namespace UE
{
	enum class EObjectFullNameFlags
	{
		None = 0,
		IncludeClassPackage = 1,
	};
	REX_DEFINE_ENUM_CLASS_FLAGS(EObjectFullNameFlags);
}
