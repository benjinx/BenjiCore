#include "EventListener.h"
#include "Services.h"


EventListener::EventListener()
{
	mRemoveOnDestruct = true;
}

EventListener::~EventListener()
{
	if (mRemoveOnDestruct)
		Services::getEventSystem()->removeListenerFromAllEvents(this);
}
