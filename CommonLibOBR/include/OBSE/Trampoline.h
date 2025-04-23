#pragma once

#include "REL/Trampoline.h"

namespace OBSE
{
	using Trampoline = REL::Trampoline;

	// DEPRECATED
	[[nodiscard]] REL::Trampoline& GetTrampoline() noexcept
	{
		return REL::GetTrampoline();
	}
}
