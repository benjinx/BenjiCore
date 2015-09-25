#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

#include "Trackable.h"
#include "SDL_Headers.h"
#include "Vector2f.h"

enum Key
{
	KEY_TILDE = SDLK_BACKQUOTE,
	KEY_1 = SDLK_1,
	KEY_2 = SDLK_2,
	KEY_3 = SDLK_3,
	KEY_4 = SDLK_4,
	KEY_5 = SDLK_5,
	KEY_6 = SDLK_6,
	KEY_7 = SDLK_7,
	KEY_8 = SDLK_8,
	KEY_9 = SDLK_9,
	KEY_0 = SDLK_0,
	KEY_F1 = SDLK_F1,
	KEY_F2 = SDLK_F2,
	KEY_F3 = SDLK_F3,
	KEY_F4 = SDLK_F4,
	KEY_F5 = SDLK_F5,
	KEY_F6 = SDLK_F6,
	KEY_F7 = SDLK_F7,
	KEY_F8 = SDLK_F8,
	KEY_F9 = SDLK_F9,
	KEY_F10 = SDLK_F10,
	KEY_F11 = SDLK_F11,
	KEY_F12 = SDLK_F12,
	KEY_LEFT = SDLK_LEFT,
	KEY_RIGHT = SDLK_RIGHT,
	KEY_DOWN = SDLK_DOWN,
	KEY_UP = SDLK_UP,
	KEY_W = SDLK_w,
	KEY_A = SDLK_a,
	KEY_S = SDLK_s,
	KEY_D = SDLK_d,
	KEY_ESCAPE = SDLK_ESCAPE,
	KEY_SPACE = SDLK_SPACE,
	KEY_ENTER = SDLK_RETURN,
};

enum MouseButton
{
	MOUSE_LEFT = SDL_BUTTON_LEFT,
	MOUSE_RIGHT = SDL_BUTTON_RIGHT,
	MOUSE_MIDDLE = SDL_BUTTON_MIDDLE,
};

class InputSystem : public Trackable
{
public:
	InputSystem();
	~InputSystem();

	// Functions
	bool isMouseDown(MouseButton button);
	bool isMousePressed(MouseButton button);
	bool isMouseReleased(MouseButton button);
	Vector2f getMousePosition() { return Vector2f((float)mX, (float)mY); }
	bool init();
	void cleanup();
	void pollInput();

private:
	bool mIsInitialized;
	bool mHasFocus;
	SDL_MouseButtonEvent* mpSDLMouseState;
	SDL_MouseButtonEvent* mpSDLMouseStatePrev;
	int mX, mY;
};

#endif