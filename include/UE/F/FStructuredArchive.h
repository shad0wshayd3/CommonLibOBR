#pragma once

#include "UE/F/FStructuredArchiveArray.h"
#include "UE/F/FStructuredArchiveMap.h"
#include "UE/F/FStructuredArchiveRecord.h"
#include "UE/F/FStructuredArchiveSlot.h"
#include "UE/F/FStructuredArchiveStream.h"

namespace UE
{
	class FStructuredArchive
	{
		friend FStructuredArchiveSlot;
		friend FStructuredArchiveRecord;
		friend FStructuredArchiveArray;
		friend FStructuredArchiveStream;
		friend FStructuredArchiveMap;

	public:
		using FSlot = FStructuredArchiveSlot;
		using FRecord = FStructuredArchiveRecord;
		using FArray = FStructuredArchiveArray;
		using FStream = FStructuredArchiveStream;
		using FMap = FStructuredArchiveMap;

		// members
		// FBinaryArchiveFormatter* formatter;
	};
}
