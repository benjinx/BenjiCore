#include "InputSystem.h"
#include "Services.h"
#include "Event.h"
#include "MouseEvent.h"

InputSystem::InputSystem()
{
}


InputSystem::~InputSystem()
{
	cleanup();
}

bool InputSystem::init()
{
	if (mIsInitialized)
		return false;

	mHasFocus = true;
	mIsInitialized = true;
	return true;
}

void InputSystem::cleanup()
{
	if (mIsInitialized)
	{
		mIsInitialized = false;
	}
}

// Handle any application messages sent after the previous frame.
void InputSystem::pollInput()
{
	SDL_Event sdlEvent;
	Vector2f mousePos;

	// Handle queued SDL events.
	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{

			// WINDOW EVENTS.
		case SDL_QUIT:
			// The window's close button was pressed!
			Services::getEventSystem()->fireEvent(Event(EVENT_GAME_EXIT));
			break;
		case SDL_WINDOWEVENT:
			if (sdlEvent.window.event == SDL_WINDOWEVENT_FOCUS_LOST)
			{
				mHasFocus = false;
				Services::getEventSystem()->fireEvent(Event(EVENT_WINDOW_LOSE_FOCUS));
				Services::getEventSystem()->fireEvent(Event(EVENT_INPUT_PAUSE_GAME));
			}
			else if (sdlEvent.window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
			{
				mHasFocus = true;
				Services::getEventSystem()->fireEvent(Event(EVENT_WINDOW_GAIN_FOCUS));
			}
			break;

			// MOUSE INPUT EVENTS:
		case SDL_MOUSEMOTION: // Mouse Coords - Used for the hover menu
			mX = (int)sdlEvent.motion.x;
			mY = (int)sdlEvent.motion.y;
			Services::getEventSystem()->fireEvent(MouseEvent(EVENT_MOUSE_HOVER, getMousePosition()));
			break;
		case SDL_MOUSEWHEEL:
			// Change items on mouse wheel.
			if (sdlEvent.wheel.y < 0) // Scrolled towards you
				Services::getEventSystem()->fireEvent(Event(EVENT_INPUT_NEXT_ITEM));
			else if (sdlEvent.wheel.y > 0) // Scrolled away from you
				Services::getEventSystem()->fireEvent(Event(EVENT_INPUT_PREVIOUS_ITEM));
			break;
		case SDL_MOUSEBUTTONDOWN:
			mousePos.set((float)sdlEvent.button.x, (float)sdlEvent.button.y);
			// ^ Click Coords - use for when you click button

			if (sdlEvent.button.button == MOUSE_LEFT)
				Services::getEventSystem()->fireEvent(MouseEvent(EVENT_MOUSE_PRESS, mousePos));

			// RIGHT MOUSE: Player movement.
			if (sdlEvent.button.button == MOUSE_RIGHT)
				Services::getEventSystem()->fireEvent(MouseEvent(EVENT_INPUT_MOVE_PLAYER, mousePos));

			// LEFT MOUSE: Player use item.
			if (sdlEvent.button.button == MOUSE_LEFT)
				Services::getEventSystem()->fireEvent(MouseEvent(EVENT_INPUT_USE_ITEM, mousePos));

			break;
		case SDL_MOUSEBUTTONUP:
			mousePos.set((float)sdlEvent.button.x, (float)sdlEvent.button.y);
			if (sdlEvent.button.button == MOUSE_LEFT)
				Services::getEventSystem()->fireEvent(MouseEvent(EVENT_MOUSE_RELEASE, mousePos));
			break;

			// KEYBOARD INPUT EVENTS:
		case SDL_KEYDOWN:
		{
							int key = sdlEvent.key.keysym.sym;

							// ENTER and ESCAPE: open pause menu.
							if (key == KEY_ENTER || key == KEY_ESCAPE)
								Services::getEventSystem()->fireEvent(Event(EVENT_INPUT_PAUSE_GAME));

							// ESCAPE: back out of a menu.
							if (key == KEY_ESCAPE)
								//Services::getEventSystem()->fireEvent(Event(EVENT_INPUT_MENU_BACK));
								Services::getEventSystem()->fireEvent(Event(EVENT_GAME_EXIT));

							// Number keys to select items from the inventory.
							//else if (key >= KEY_1 && key <= KEY_9)
								//Services::getEventSystem()->fireEvent(IntEvent(EVENT_INPUT_SELECT_ITEM, key - KEY_1));

							// Menu Keys
							else if (key == KEY_LEFT)
								Services::getEventSystem()->fireEvent(Event(EVENT_MENU_KEY_LEFT));
							else if (key == KEY_RIGHT)
								Services::getEventSystem()->fireEvent(Event(EVENT_MENU_KEY_RIGHT));
							else if (key == KEY_DOWN)
								Services::getEventSystem()->fireEvent(Event(EVENT_MENU_KEY_DOWN));
							else if (key == KEY_UP)
								Services::getEventSystem()->fireEvent(Event(EVENT_MENU_KEY_UP));
							else if (key == KEY_ENTER)
								Services::getEventSystem()->fireEvent(Event(EVENT_MENU_PRESS_BUTTON));

							// DEBUG: Keys
							else if (key == KEY_F1)
								Services::getEventSystem()->fireEvent(Event(EVENT_DEBUG_SAVE_LEVEL_STATE));
							else if (key == KEY_F2)
								Services::getEventSystem()->fireEvent(Event(EVENT_DEBUG_LOAD_LEVEL_STATE));
							else if (key == KEY_F4)
								Services::getEventSystem()->fireEvent(Event(EVENT_DEBUG_RESTOCK_ITEMS));
							else if (key == KEY_F5)
								Services::getEventSystem()->fireEvent(Event(EVENT_DEBUG_LEVEL_SUCCESS));
							else if (key == KEY_F6)
								Services::getEventSystem()->fireEvent(Event(EVENT_DEBUG_LEVEL_FAILURE));
								
							break;
		}
		case SDL_KEYUP:
		{
						  int key = sdlEvent.key.keysym.sym;

						  // Menu keys
						  if (key == KEY_ENTER)
							  Services::getEventSystem()->fireEvent(Event(EVENT_MENU_RELEASE_BUTTON));

						  break;
		}
		}
	}
}