#pragma once

namespace RE
{
	enum class SCRIPT_ERROR : std::int32_t
	{
		kNoError,
		kScriptNameMissing,
		kSyntax,
		kBadVariableName,
		kUnknownVariable,
		kNoCommands,
		kExpression,
		kMissingSetVarAlias,
		kWhileStackOverflow,
		kWhileStackUnderflow,
		kIfStackOverflow,
		kIfStackUnderflow,
		kOutOfMemory,
		kUnhandledCommand,
		kFileType,
		kFileCorrupt,
		kLineTooLong,
		kUnknownObject,
	};
}
