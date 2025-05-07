#pragma once

namespace RE::UE
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

	class FStructuredArchiveRecord :
		public StructuredArchive::Private::FSlotBase
	{
	public:
	};
	static_assert(sizeof(FStructuredArchiveRecord) == 0x08);
}
