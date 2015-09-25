#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <trackable.h>


enum EventType
{
	INVALID_EVENT_TYPE = -1,

	// Display
	EVENT_WINDOW_LOSE_FOCUS,	// The game is no longer the active window.
	EVENT_WINDOW_GAIN_FOCUS,	// The game has now become the active window.

	// Game
	//EVENT_GAME_START,			// Game is going to start
	//EVENT_GAME_OVER,			// Game has ended.
	EVENT_GAME_EXIT,			// Exit the game.

	// Input
	EVENT_INPUT_START_GAME,		// Player has chosen to start the game or play again.
	EVENT_INPUT_USE_ITEM,		// Player has chosen to use item - left click
	EVENT_INPUT_MOVE_PLAYER,	// Move player - right click
	EVENT_INPUT_NEXT_ITEM,		// Select the next item
	EVENT_INPUT_PREVIOUS_ITEM,	// Select the previous item.
	EVENT_INPUT_SELECT_ITEM,	// Select an item by index.
	EVENT_INPUT_PAUSE_GAME,		// Open the pause menu.
	EVENT_INPUT_MENU_BACK,		// Go back in a menu system.
	EVENT_MOUSE_PRESS,
	EVENT_MOUSE_RELEASE,
	EVENT_MOUSE_HOVER,

	// Entity
	EVENT_ENTITY_CREATE,		// Entity was created
	EVENT_ENTITY_DESTORY,		// Entity has been destroyed
	EVENT_ENTITY_COLLIDE_SOLID,	// The physics-entity collided with a solid tile (walls)

	// Unit
	EVENT_UNIT_COLLIDE_UNIT,	// The unit collided with another unit.
	EVENT_UNIT_DIE,				// A unit died.

	// Enemy
	EVENT_ENEMY_DIE,			// An enemy unit has died.

	// Player
	EVENT_PLAYER_DIE,			// Player has died.
	EVENT_PLAYER_RESPAWN,		// Player has been revived
	EVENT_PLAYER_STAB,			// Player stabbed with his knife
	EVENT_PLAYER_SLAP,			// Player slaps with his rubber chicken

	// Items
	EVENT_DETONATE_TNT,			// The detonator was used.
	EVENT_EXPLOSION,			// An explosion was created.

	// Menu Keys
	EVENT_MENU_KEY_LEFT,
	EVENT_MENU_KEY_RIGHT,
	EVENT_MENU_KEY_DOWN,
	EVENT_MENU_KEY_UP,
	EVENT_MENU_PAUSE_GAME,
	EVENT_MENU_PRESS_BUTTON,
	EVENT_MENU_RELEASE_BUTTON,

	// DEBUG
	EVENT_DEBUG_SAVE_LEVEL_STATE,
	EVENT_DEBUG_LOAD_LEVEL_STATE,
	EVENT_DEBUG_RESTOCK_ITEMS,
	EVENT_DEBUG_LEVEL_SUCCESS,
	EVENT_DEBUG_LEVEL_FAILURE,

	NUM_EVENT_TYPES
};


class Event : public Trackable
{
public:
	Event(EventType type) :
		mType(type)
	{

	}
	virtual ~Event() {}

	EventType getType() const { return mType; };

private:
	EventType mType;
};


#endif // EVENT_H