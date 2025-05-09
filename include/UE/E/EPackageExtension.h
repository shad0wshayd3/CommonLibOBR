#pragma once

namespace UE
{
	enum class EPackageExtension : std::uint8_t
	{
		Unspecified = 0,
		Asset,
		Map,
		TextAsset,
		TextMap,
		Custom,
		EmptyString,
		Exports,
		BulkDataDefault,
		BulkDataOptional,
		BulkDataMemoryMapped,
		PayloadSidecar,
	};
}
