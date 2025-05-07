#pragma once

namespace UE::Math
{
	template <typename T>
	class TVector
	{
	public:
		// members
		union
		{
			union
			{
				T x;
				T y;
				T z;
			};
			T xyz[3];
		};
	};
	static_assert(sizeof(TVector<double>) == 0x18);
}
