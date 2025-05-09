#pragma once

namespace UE
{
	class FField;
	class UObject;

	class FFieldVariant
	{
	public:

		// members
		union FFieldObjectUnion
		{
			FField*  field;
			UObject* object;
		} container;
	};
}
