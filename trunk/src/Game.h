#ifndef GAME_H
#define GAME_H

#include <assert.h>
#include "EventListener.h"
#include "Event.h"

#include "GraphicsSystem.h"
#include "InputSystem.h"
#include "EventSystem.h"

#include "Animation.h"
#include "Entity.h"

class Game : public EventListener
{
public:
	// Singleton
	static Game* getInstance()		{ assert(mspGameInstance != NULL); return mspGameInstance; }
	static void  initInstance()		{ mspGameInstance = new Game(); }
	static void  cleanupInstance()	{ delete mspGameInstance; }

	bool init();
	void cleanup();
	void gameLoop();
	void update(float timeDelta);
	void draw();
	void endGame();

	// Events
	void handleEvent(const Event& theEvent);

private:
	Game();
	~Game();
	static Game* mspGameInstance;

	bool mIsInitialized;
	bool mIsGameRunning;

	// Systems
	GraphicsSystem mGraphicsSystem;
	InputSystem mInputSystem;
	EventSystem mEventSystem;



	// Test
	Texture* mpStillKirbyTex;
	Texture* mpMovingKirbyTex;
	Texture* mpBackgroundTex;
	Sprite* mpKirbySprite;
	Animation* mpKirbyAnim;
	Entity* mpKirbyE;
	Sprite* mpKirbySprites[12];
	Sprite* mpBackgroundSprite;
	Rect* mpBackgroundRect;

};

#endif