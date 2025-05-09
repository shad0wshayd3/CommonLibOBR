#pragma once

namespace UE
{
	struct FNameEntryHeader
	{
		std::uint16_t wide: 1;
		std::uint16_t lowercase : 5;
		std::uint16_t length: 10;
	};

	class FNameEntry
	{
	public:
		bool IsWide() const
		{
			return header.wide;
		}

		// members
		FNameEntryHeader header;  // 00

		union
		{
			char    ansi[1024];
			wchar_t wide[1024];
		};
	};
}
