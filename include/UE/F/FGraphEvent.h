#pragma once

#include "UE/T/TRefCountPtr.h"

namespace UE
{
	class FGraphEvent;

	using FGraphEventRef = TRefCountPtr<FGraphEvent>;
}
