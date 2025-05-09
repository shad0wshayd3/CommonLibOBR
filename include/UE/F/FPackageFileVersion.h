#pragma once

namespace UE
{
	class FPackageFileVersion
	{
	public:
		// members
		std::int32_t fileVersionUE4{ 0 };
		std::int32_t fileVersionUE5{ 0 };
	};
	static_assert(sizeof(FPackageFileVersion) == 0x8);
}
