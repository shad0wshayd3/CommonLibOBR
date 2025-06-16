#pragma once

#include "RE/N/NiBinaryStream.h"

namespace RE
{
	class NiFile :
		public NiBinaryStream
	{
	public:
		enum OpenMode
		{
			kReadOnly,
			kWriteOnly,
			kAppendOnly,
		};

		// override
		virtual ~NiFile();  // 00

		virtual      operator bool() override;             // 01
		virtual void SetEndianSwap(bool a_swap) override;  // 02

		// add
		virtual void          Seek(std::int32_t a_offset, std::int32_t a_whence);  // 04
		virtual std::uint32_t GetFileSize();                                       // 05

		// members
		std::uint32_t bufferAllocSize;  // 18
		std::uint32_t bufferReadSize;   // 1C
		std::uint32_t pos;              // 20
		char*         buffer;           // 28
		void*         file;             // 30
		OpenMode      mode;             // 38
		bool          good;             // 3C
	};
	static_assert(sizeof(NiFile) == 0x40);
}
