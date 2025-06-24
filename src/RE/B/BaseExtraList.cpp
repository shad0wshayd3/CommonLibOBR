#include "RE/B/BaseExtraList.h"
#include "RE/B/BSExtraData.h"

namespace RE
{
	BSExtraData* BaseExtraList::Get(ExtraDataType type) const
	{
		if (!Contains(type))
			return nullptr;

		for (const BSExtraData& data : *this)
		{
			if (data.type == type)
				return const_cast<BSExtraData*>(&data);
		}

		return nullptr;
	}

	bool BaseExtraList::Contains(ExtraDataType type) const
	{
		if (type >= ExtraDataType::Max)
			return false;

		return (flags[(std::uint8_t)type >> 3] >> ((std::uint8_t)type & 7)) & 1;
	}
}
