#include "Input.h"

// - Event handlers

void handleKeyboardKey(sfKeyCode code, KEYS keyCode, bool kP[], bool kH[])
{
	if (sfKeyboard_isKeyPressed(code))
	{
		if (!kP[keyCode] && !kH[keyCode])
		{
			kP[keyCode] = true;
		}
		else if (!kH[keyCode])
		{
			kP[keyCode] = false;
			kH[keyCode] = true;
		}
	}
	else
	{
		kP[keyCode] = false;
		kH[keyCode] = false;
	}
}

void handleMouseKey(sfMouseButton code, KEYS keyCode, bool kP[], bool kH[])
{
	if (sfMouse_isButtonPressed(code))
	{
		if (!kP[keyCode] && !kH[keyCode])
		{
			kP[keyCode] = true;
		}
		else if (!kH[keyCode])
		{
			kP[keyCode] = false;
			kH[keyCode] = true;
		}
	}
	else
	{
		kP[keyCode] = false;
		kH[keyCode] = false;
	}
}