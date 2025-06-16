#pragma once

#include "RE/S/Setting.h"
#include "RE/S/SettingCollectionList.h"

namespace RE
{
	class INISettingCollection :
		public SettingCollectionList<Setting>
	{
	public:
		inline static constexpr auto RTTI = RTTI::INISettingCollection;
		inline static constexpr auto VTABLE = VTABLE::INISettingCollection;

		virtual ~INISettingCollection() override;  // 00

		// override
		virtual std::uint32_t GetViewerStrings(NiTArray<char*>* a_strings) override;  // 03
		virtual bool          WriteSetting(Setting& a_setting) override;              // 04
		virtual bool          ReadSetting(Setting& a_setting) override;               // 05
		virtual bool          Open(bool a_write) override;                            // 06
		virtual bool          Close() override;                                       // 07

		static INISettingCollection* GetSingleton()
		{
			static REL::Relocation<INISettingCollection*> singleton{ ID::INISettingCollection::Singleton };
			return singleton.get();
		}
	};
	static_assert(sizeof(INISettingCollection) == 0x128);
}
