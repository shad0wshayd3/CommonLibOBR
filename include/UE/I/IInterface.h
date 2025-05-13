#pragma once

#define UE_DEFINE_IINTERFACE(a_package, a_name)       \
	static constexpr auto UE_PACKAGE{ L##a_package }; \
	static constexpr auto UE_NAME{ L##a_name };       \
	static constexpr auto UE_CLASS{ L"/Script/" L##a_package L"." L##a_name };
