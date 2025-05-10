#pragma once

namespace RE
{
	enum class TES_RETURN_CODE : std::int32_t
	{
		kNone = 0,
		kNotFound = 1,
		kNoFile = 2,
		kNoForm = 3,
		kNoChunk = 4,
		kNoID = 5,
		kBadFile = 6,
		kBadID = 7,
		kFormOpen = 8,
		kFileOpen = 9,
		kWriteFailure = 10,
		kInvalidFile = 11,
		kFileInUse = 12,
		kCreateFailure = 13
	};
}
