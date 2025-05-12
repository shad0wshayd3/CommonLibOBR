#pragma once

namespace UE::Math
{
	template <class T>
	class alignas(16) TQuat
	{
	public:
		// members
		T x;
		T y;
		T z;
		T w;
	};
	static_assert(sizeof(TQuat<double>) == 0x20);
}

namespace UE
{
	using FQuat = Math::TQuat<double>;
	using FQuat4d = Math::TQuat<double>;
	using FQuat4f = Math::TQuat<float>;
}
