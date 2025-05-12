#pragma once

namespace UE
{
	enum class EComponentCreationMethod : std::uint8_t
	{
		Native,
		SimpleConstructionScript,
		UserConstructionScript,
		Instance,
	};
}
