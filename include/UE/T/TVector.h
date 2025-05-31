#pragma once

namespace UE::Math
{
	template <class T>
	class TVector
	{
	public:
		constexpr TVector() :
			x(0), y(0), z(0)
		{}

		constexpr TVector(T a_x, T a_y, T a_z) :
			x(a_x), y(a_y), z(a_z)
		{}

		// members
		union
		{
			struct
			{
				T x;
				T y;
				T z;
			};
			T xyz[3];
		};
	};
	static_assert(sizeof(TVector<float>) == 0xC);
	static_assert(sizeof(TVector<double>) == 0x18);
}
