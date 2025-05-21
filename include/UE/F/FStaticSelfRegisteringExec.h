#pragma once

#include "UE/F/FSelfRegisteringExec.h"

namespace UE
{
	class FStaticSelfRegisteringExec :
		public FSelfRegisteringExec
	{
		using Func = bool (*)(UWorld*, const wchar_t*, FOutputDevice&);

	public:
		FStaticSelfRegisteringExec(bool (*a_func)(UWorld* a_world, const wchar_t* a_cmd, FOutputDevice& a_output)) :
			m_func(a_func)
		{}

		virtual bool Exec(UE::UWorld* a_world, const wchar_t* a_cmd, UE::FOutputDevice& a_output) override
		{
			return (*m_func)(a_world, a_cmd, a_output);
		}

	private:
		Func m_func;
	};
	static_assert(sizeof(FSelfRegisteringExec) == 0x8);
}
