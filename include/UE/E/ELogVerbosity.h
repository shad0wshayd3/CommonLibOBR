#pragma once

namespace UE
{
	enum class ELogVerbosity : std::uint8_t
	{
		NoLogging = 0,
		Fatal,
		Error,
		Warning,
		Display,
		Log,
		Verbose,
		VeryVerbose,
		All = VeryVerbose,
		NumVerbosity,
		VerbosityMask = 0xF,
		SetColor = 0x40,
		BreakOnLog = 0x80
	};
}
