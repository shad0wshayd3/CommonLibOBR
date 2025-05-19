#pragma once

#include <REX/Impl/PCH.h>

namespace OBSE
{
	using namespace std::literals;
	namespace stl = XSE::stl;

	struct VersionPackInfo
	{
		static constexpr auto AND_MAJOR{ 0x00F };
		static constexpr auto AND_MINOR{ 0xFFF };
		static constexpr auto AND_PATCH{ 0xFFF };
		static constexpr auto AND_BUILD{ 0x00F };
		static constexpr auto SHL_MAJOR{ 28 };
		static constexpr auto SHL_MINOR{ 16 };
		static constexpr auto SHL_PATCH{ 4 };
		static constexpr auto SHL_BUILD{ 0 };
	};

	using Version = REL::VersionBase<VersionPackInfo>;
}

namespace RE
{
	using namespace std::literals;
	namespace stl = XSE::stl;
}

#include "RE/IDs.h"
#include "RE/NiRTTI_IDs.h"
#include "RE/RTTI_IDs.h"
#include "RE/VTABLE_IDs.h"

#include "RE/B/BSCoreTypes.h"
