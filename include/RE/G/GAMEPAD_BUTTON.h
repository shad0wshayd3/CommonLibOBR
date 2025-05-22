#pragma once

namespace RE
{
	enum class GAMEPAD_BUTTON : std::int32_t
	{
		kButtonNone = 0,
		kButtonDPadUp = 1,
		kButtonDPadDown = 2,
		kButtonDPadRight = 3,
		kButtonDPadLeft = 4,
		kButtonStart = 5,
		kButtonBack = 6,
		kButtonLThumb = 7,
		kButtonRThumb = 8,
		kButtonA = 9,
		kButtonB = 10,
		kButtonX = 11,
		kButtonY = 12,
		kButtonLT = 13,
		kButtonRT = 14,
		kButtonLB = 15,
		kButtonRB = 16,
		kButtonDownEvent = 2,
		kButtonUpEvent = 1,
		kButtonStillDownEvent = 0,
		kButtonIdleEvent = -1,
		kButtonClick = -2,
	};
}
