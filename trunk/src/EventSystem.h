#ifndef EVENT_SYSTEM_H
#define EVENT_SYSTEM_H

#include <map>
#include <Trackable.h>

class Event;
class EventListener;
enum EventType;


class EventSystem :public Trackable
{
	typedef std::multimap<EventType, EventListener*> EventMultiMap;

public:
	EventSystem();
	~EventSystem();

	void fireEvent(const Event& theEvent);
	void addListener(EventType type, EventListener* pListener);
	void removeListener(EventType type, EventListener* pListener);
	void removeListenerFromAllEvents(EventListener* pListener);

private:
	static EventSystem* msInstance;

	void dispatchAllEvents(const Event& theEvent);
	
	EventMultiMap mListenerMap;
};

extern EventSystem* gpEventSystem;


#endif // EVENT_SYSTEM_H