#pragma once

#include "UE/F/FUObjectItem.h"

namespace UE
{
	class FChunkedFixedUObjectArray
	{
	public:
		static constexpr std::uint32_t NumElementsPerChunk{ 64 * 1024 };

		std::int32_t Capacity() const
		{
			return maxElements;
		}

		std::int32_t Num() const
		{
			return numElements;
		}

		bool IsValidIndex(std::int32_t a_index) const
		{
			return a_index < Num() && a_index >= 0;
		}

		const FUObjectItem* GetObjectPtr(std::int32_t a_index) const
		{
			assert(IsValidIndex(a_index));

			const std::uint32_t chunkIndex = (std::uint32_t)a_index / NumElementsPerChunk;
			const std::uint32_t withinChunkIndex = (std::uint32_t)a_index % NumElementsPerChunk;

			FUObjectItem* chunk = objects[chunkIndex];
			return chunk + withinChunkIndex;
		}

		FUObjectItem* GetObjectPtr(std::int32_t a_index)
		{
			assert(IsValidIndex(a_index));

			const std::uint32_t chunkIndex = (std::uint32_t)a_index / NumElementsPerChunk;
			const std::uint32_t withinChunkIndex = (std::uint32_t)a_index % NumElementsPerChunk;

			FUObjectItem* chunk = objects[chunkIndex];
			return chunk + withinChunkIndex;
		}

		FUObjectItem const& operator[](std::int32_t a_index) const
		{
			const FUObjectItem* item = GetObjectPtr(a_index);

			assert(item);

			return *item;
		}

		FUObjectItem& operator[](std::int32_t a_index)
		{
			FUObjectItem* item = GetObjectPtr(a_index);

			assert(item);

			return *item;
		}

		// members
		FUObjectItem** objects;              // 00
		FUObjectItem*  preAllocatedObjects;  // 08
		std::int32_t   maxElements;          // 10
		std::int32_t   numElements;          // 14
		std::int32_t   maxChunks;            // 18
		std::int32_t   numChunks;            // 1C
	};
	static_assert(sizeof(FChunkedFixedUObjectArray) == 0x20);
}
