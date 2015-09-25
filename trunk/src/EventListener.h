#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

#include <Trackable.h>

class Event;

class EventListener : public Trackable
{
public:
	EventListener();
	virtual ~EventListener();

	virtual bool canHandleEvents() { return true; }
	virtual void handleEvent(const Event& theEvent) = 0;

	inline void setRemoveOnDestruct(bool removeOnDestruct) { mRemoveOnDestruct = removeOnDestruct; }

private:
	bool mRemoveOnDestruct; // Should this listener remove itself from the event system upon destruction?
};

#endif