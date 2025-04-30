#pragma once

namespace RE
{
	class Setting
	{
	public:
		enum class Type
		{
			kUnknown = 0,
			kBool,
			kFloat,
			kSignedInteger,
			kColor,
			kString,
			kUnsignedInteger
		};

		union Data
		{
			bool          b;
			float         f;
			std::int32_t  i;
			std::uint32_t r;
			char*         s;
			std::uint32_t u;
		};
		static_assert(sizeof(Data) == 0x8);

		[[nodiscard]] bool        IsManaged() const;
		[[nodiscard]] Type        GetType() const;
		[[nodiscard]] const char* GetName() const;

		[[nodiscard]] bool                             GetBool() const;
		[[nodiscard]] float                            GetFloat() const;
		[[nodiscard]] std::int32_t                     GetSInt() const;
		[[nodiscard]] std::span<const std::uint8_t, 3> GetColor() const;
		[[nodiscard]] const char*                      GetString() const;
		[[nodiscard]] std::uint32_t                    GetUInt() const;

		void SetString(const char* a_value);

		// members
		Data  data;  // 00
		char* name;  // 08
	};
	static_assert(sizeof(Setting) == 0x10);
}
