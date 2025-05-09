#pragma once

namespace UE
{
	class FStructuredArchive;

	namespace StructuredArchive::Private
	{
		class FSlotBase
		{
		public:
			// members
			FStructuredArchive* structuredArchive;  // 00
		};
		static_assert(sizeof(FSlotBase) == 0x08);
	}
}
