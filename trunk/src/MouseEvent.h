#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H

#include "Event.h"
#include "Vector2f.h"

class MouseEvent : public Event
{
public:
	MouseEvent(EventType type, const Vector2f& position) :
		Event(type),
		mPosition(position)
	{
	}

	// Accessors
	inline Vector2f getLocation() const { return mPosition; }

private:
	Vector2f mPosition;
};

#endif