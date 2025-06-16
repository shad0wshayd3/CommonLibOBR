#pragma once

#include "RE/N/NiTArray.h"

namespace RE
{
	template <class T>
	class SettingCollection
	{
	public:
		virtual ~SettingCollection();  // 00

		// add
		virtual void          Add(T* a_setting) = 0;                             // 01
		virtual void          Remove(T* a_setting) = 0;                          // 02
		virtual std::uint32_t GetViewerStrings(NiTArray<char*>* a_strings) = 0;  // 03
		virtual bool          WriteSetting(T& a_setting) = 0;                    // 04
		virtual bool          ReadSetting(T& a_setting) = 0;                     // 05
		virtual bool          Open(bool a_write) = 0;                            // 06
		virtual bool          Close() = 0;                                       // 07
		virtual bool          WriteSettings() = 0;                               // 08
		virtual bool          ReadSettings() = 0;                                // 09

		// members
		char  subKey[0x104];  // 008
		void* handle;         // 110
	};
	static_assert(sizeof(SettingCollection<void*>) == 0x118);
}
