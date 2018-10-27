#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>

#include "Enums.h"

#ifndef INPUT
#define INPUT

enum KEYS
{
	A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,

	SHIFT_L, SHIFT_R,
	CTRL_L, CTRL_R,

	TAB,
	SPACE,
	ESCAPE,

	ARROW_UP, ARROW_DOWN,
	ARROW_LEFT, ARROW_RIGHT,

	LMB, MMB, RMB,

	NBKEYS
};
//Keys useable
typedef enum KEYS KEYS;


// - Event handlers

void handleKeyboardKey(sfKeyCode code, KEYS keyCode, bool kP[], bool kH[]);
void handleMouseKey(sfMouseButton code, KEYS keyCode, bool kP[], bool kH[]);

#endif//INPUT