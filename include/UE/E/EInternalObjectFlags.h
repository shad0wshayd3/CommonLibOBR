#pragma once

namespace UE
{
	enum class EInternalObjectFlags : std::int32_t
	{
		None = 0,

		LoaderImport = 1 << 20,
		Garbage = 1 << 21,
		ReachableInCluster = 1 << 23,
		ClusterRoot = 1 << 24,
		Native = 1 << 25,
		Async = 1 << 26,
		AsyncLoading = 1 << 27,
		Unreachable = 1 << 28,
		PendingKill = 1 << 29,
		RootSet = 1 << 30,
		PendingConstruction = 1 << 31,

		GarbageCollectionKeepFlags = Native | Async | AsyncLoading | LoaderImport,
		MirroredFlags = Garbage | PendingKill,

		AllFlags = LoaderImport | Garbage | ReachableInCluster | ClusterRoot | Native | Async | AsyncLoading | Unreachable | PendingKill | RootSet | PendingConstruction
	};
	REX_DEFINE_ENUM_CLASS_FLAGS(EInternalObjectFlags);
}
