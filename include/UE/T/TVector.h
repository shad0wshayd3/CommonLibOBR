#pragma once

namespace UE::Math
{
	template <class T>
	class TVector
	{
	public:
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
	static_assert(sizeof(TVector<double>) == 0x18);
}

namespace UE
{
	using FVector = Math::TVector<double>;
	using FVector3d = Math::TVector<double>;
	using FVector3f = Math::TVector<float>;
}
