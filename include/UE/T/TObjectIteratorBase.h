#pragma once

#include "UE/F/FUObjectArray.h"
#include "UE/U/UObject.h"

namespace UE
{
	enum class EObjectIteratorThreadSafetyOptions : std::uint8_t
	{
		None = 0,
		ThreadSafe = 1,
		ThreadSafeAdvance = 2
	};

	inline EInternalObjectFlags GetObjectIteratorDefaultInternalExclusionFlags(EInternalObjectFlags a_internalExclusionFlags)
	{
		a_internalExclusionFlags |= EInternalObjectFlags::Unreachable | EInternalObjectFlags::PendingConstruction;

		return a_internalExclusionFlags;
	}

	template <EObjectIteratorThreadSafetyOptions E>
	class TObjectIteratorBase :
		public FUObjectArray::TIterator
	{
	public:
		explicit TObjectIteratorBase(UClass* a_class = FindClass<UObject>(), bool a_onlyGCedObjects = false, EObjectFlags a_additionalExclusionFlags = EObjectFlags::NoFlags, EInternalObjectFlags a_internalExclusionFlags = EInternalObjectFlags::None) :
			FUObjectArray::TIterator(*FUObjectArray::GetSingleton(), a_onlyGCedObjects), classPrivate(a_class), exclusionFlags(a_additionalExclusionFlags), internalExclusionFlags(GetObjectIteratorDefaultInternalExclusionFlags(a_internalExclusionFlags))
		{
			if (E == EObjectIteratorThreadSafetyOptions::ThreadSafe)
				GetIteratedArray().LockInternalArray();

			do {
				UObject* object = **this;
				if (!(object->HasAnyFlags(exclusionFlags) || object->HasAnyInternalFlags(internalExclusionFlags) || (classPrivate != FindClass<UObject>() && !object->IsA(classPrivate))))
					break;
			} while (AdvanceIterator());
		}

		TObjectIteratorBase(const TObjectIteratorBase& a_other) :
			FUObjectArray::TIterator(a_other), classPrivate(a_other.classPrivate), exclusionFlags(a_other.exclusionFlags), internalExclusionFlags(a_other.internalExclusionFlags)
		{
			if (E == EObjectIteratorThreadSafetyOptions::ThreadSafe)
				GetIteratedArray().LockInternalArray();
		}

		~TObjectIteratorBase()
		{
			if (E == EObjectIteratorThreadSafetyOptions::ThreadSafe)
				GetIteratedArray().UnlockInternalArray();
		}

		void operator++()
		{
			while (AdvanceIterator()) {
				UObject* object = **this;
				if (!(object->HasAnyFlags(exclusionFlags) || (classPrivate != FindClass<UObject>() && !object->IsA(classPrivate)) || object->HasAnyInternalFlags(internalExclusionFlags))) {
					break;
				}
			}
		}

		UObject* operator*() const
		{
			const auto item = GetObject();
			return item ? static_cast<UObject*>(item->object) : nullptr;
		}

		UObject* operator->() const
		{
			const auto item = GetObject();
			return item ? static_cast<UObject*>(item->object) : nullptr;
		}

	private:
		bool AdvanceIterator()
		{
			bool result = false;
			if (E != EObjectIteratorThreadSafetyOptions::ThreadSafeAdvance) {
				result = Advance();
			} else {
				GetIteratedArray().LockInternalArray();
				result = Advance();
				GetIteratedArray().UnlockInternalArray();
			}

			return result;
		}

	protected:
		UClass*              classPrivate;
		EObjectFlags         exclusionFlags;
		EInternalObjectFlags internalExclusionFlags;
	};

	using FThreadSafeObjectIterator = TObjectIteratorBase<EObjectIteratorThreadSafetyOptions::ThreadSafe>;
	using FPersistentThreadSafeObjectIterator = TObjectIteratorBase<EObjectIteratorThreadSafetyOptions::ThreadSafeAdvance>;
}
