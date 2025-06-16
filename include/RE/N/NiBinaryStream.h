#pragma once

namespace RE
{
	class NiBinaryStream
	{
	public:
		using read_t = std::uint32_t(NiBinaryStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
		using write_t = std::uint32_t(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);

		// add
		virtual ~NiBinaryStream();                // 00
		virtual      operator bool();             // 01
		virtual void SetEndianSwap(bool a_swap);  // 02

		// members
		read_t*  fnRead;   // 08
		write_t* fnWrite;  // 10
	};
	static_assert(sizeof(NiBinaryStream) == 0x18);
}
