#ifndef SERVICES_H
#define SERVICES_H

#include "Trackable.h"
#include "GraphicsSystem.h"
#include "InputSystem.h"
#include "EventSystem.h"

class Services : public Trackable
{
public:
	inline static Services* getInstance() { return mspInstance; }
	static bool init();
	static void cleanup();

	// Service Access
	inline static GraphicsSystem* getGraphicsSystem() { return getInstance()->mpGraphicsSystem; }
	inline static InputSystem* getInputSystem() { return getInstance()->mpInputSystem; }
	inline static EventSystem* getEventSystem() { return getInstance()->mpEventSystem; }

	// Service provision
	inline static void provideGraphicsSystem(GraphicsSystem* pGraphics) { getInstance()->mpGraphicsSystem = pGraphics; }
	inline static void provideInputSystem(InputSystem* pInputSystem) { getInstance()->mpInputSystem = pInputSystem; }
	inline static void provideEventSystem(EventSystem* pEventSystem) { getInstance()->mpEventSystem = pEventSystem; }

private:
	Services();
	~Services(){};

	static Services* mspInstance;

	// Services
	GraphicsSystem* mpGraphicsSystem;
	InputSystem* mpInputSystem;
	EventSystem* mpEventSystem;
};

#endif