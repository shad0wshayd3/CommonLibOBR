#pragma once

#include "UE/F/FCriticalSection.h"

namespace UE
{
	class FScopeLock
	{
	public:
		FScopeLock(FCriticalSection* a_object) :
			synchObject(a_object)
		{
			assert(synchObject);
			synchObject->Lock();
		}

		~FScopeLock()
		{
			if (synchObject) {
				synchObject->Unlock();
				synchObject = nullptr;
			}
		}

	private:
		FScopeLock();
		FScopeLock(const FScopeLock&);

		FScopeLock& operator=(FScopeLock&)
		{
			return *this;
		}

	private:
		FCriticalSection* synchObject;
	};
}
