#pragma once

#include "UE/T/TArray.h"

namespace UE
{
	class FWorldPartitionStreamingSource;
	class UObject;

	class IWorldPartitionStreamingSourceProvider
	{
	public:
		virtual bool           GetStreamingSource(FWorldPartitionStreamingSource& a_source) const;
		virtual bool           GetStreamingSources(TArray<FWorldPartitionStreamingSource>& a_sources) const;
		virtual const UObject* GetStreamingSourceOwner() const;
	};
}
