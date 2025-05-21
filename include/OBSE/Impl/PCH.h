#pragma once

#include <REL/REL.h>
#include <REX/REX.h>

namespace OBSE
{
	using namespace std::literals;

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
}

#include "RE/IDs.h"
#include "RE/IDs_NiRTTI.h"
#include "RE/IDs_RTTI.h"
#include "RE/IDs_VTABLE.h"

#include "RE/B/BSCoreTypes.h"
