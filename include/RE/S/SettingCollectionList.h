#pragma once

#include "RE/B/BSTList.h"
#include "RE/S/Setting.h"
#include "RE/S/SettingCollection.h"

namespace RE
{
	template <class T>
	class SettingCollectionList :
		public SettingCollection<T>
	{
	public:
		~SettingCollectionList() override;  // 00

		// override
		virtual void          Add(T* a_setting) override;                             // 01
		virtual void          Remove(T* a_setting) override;                          // 02
		virtual std::uint32_t GetViewerStrings(NiTArray<char*>* a_strings) override;  // 03
		virtual bool          WriteSettings() override;                               // 08
		virtual bool          ReadSettings() override;                                // 09

		// members
		BSSimpleList<T*> settings;  // 118
	};
	static_assert(sizeof(SettingCollectionList<Setting>) == 0x128);
}
