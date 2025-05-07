#pragma once

namespace RE::UE
{
	class FOutputDevice;
	class UWorld;

	class FExec
	{
	public:
		// add
		virtual ~FExec();                                                    // 00
		virtual bool Exec(UWorld*, const wchar_t*, FOutputDevice*);          // 01
		virtual bool Exec_Runtime(UWorld*, const wchar_t*, FOutputDevice*);  // 02
		virtual bool Exec_Dev(UWorld*, const wchar_t*, FOutputDevice*);      // 03
		virtual bool Exec_Editor(UWorld*, const wchar_t*, FOutputDevice*);   // 04
	};
	static_assert(sizeof(FExec) == 0x08);
}
