#pragma once

namespace RE
{
	class Interface
	{
	public:
		enum class enumGamepadButtons;
		enum class enumLoadingSection;
		enum class enumMenus;
		enum class enumParamType;
		enum class enumTargetType;
	};
	static_assert(std::is_empty_v<Interface>);
}
