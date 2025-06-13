#pragma once

namespace UE
{
	enum class EVCharacterRefreshSelector : std::uint8_t
	{
		None = 0,
		BodySection = 1,
		BodyPart = 2,
		Phenotype = 4,
		Weapons = 8,
		All = 15,
	};
}
