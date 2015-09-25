#include "Rect.h"


//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

Rect::Rect(float x, float y, float width, float height)
{
	set(x, y, width, height);
}

Rect::Rect(const Vector2f& position, const Vector2f& size) :
mPosition(position),
mSize(size)
{
}



//-----------------------------------------------------------------------------
// Mutators
//-----------------------------------------------------------------------------

// Set the rectangle's components.
void Rect::set(float x, float y, float width, float height)
{
	mPosition.set(x, y);
	mSize.set(width, height);
}

// Inflate the bounds of the rect by an equal amount on all sides.
void Rect::inflate(float amount)
{
	mPosition.x -= amount;
	mPosition.y -= amount;
	mSize.x += amount * 2.0f;
	mSize.y += amount * 2.0f;
}

// Inflate the bounds of the rect by an equal amount on all sides.
void Rect::inflate(float amountX, float amountY)
{
	mPosition.x -= amountX;
	mPosition.y -= amountY;
	mSize.x += amountX * 2.0f;
	mSize.y += amountY * 2.0f;
}


//-----------------------------------------------------------------------------
// Intersection
//-----------------------------------------------------------------------------

// Is a point contained inside this rectangle?
bool Rect::contains(const Vector2f& point) const
{
	return (point.x >= mPosition.x && point.y >= mPosition.y &&
		point.x < mPosition.x + mSize.x && point.y < mPosition.y + mSize.y);
}

// Are two rectangles intersecting?
bool Rect::intersects(const Rect& other) const
{
	return !(other.getLeft() - getRight() >= 0.0f ||
		other.getTop() - getBottom() >= 0.0f ||
		getLeft() - other.getRight() >= 0.0f ||
		getTop() - other.getBottom() >= 0.0f);
}

// Does this rectangle intersect with a line-segment?
bool Rect::intersectsSegment(const Vector2f& end1, const Vector2f& end2) const
{
	// Find min and max X for the segment.
	float minX = end1.x;
	float maxX = end2.x;
	if (end1.x > end2.x)
	{
		minX = end2.x;
		maxX = end1.x;
	}

	// Find the intersection of the segment's and rectangle's x-projections
	if (maxX > getRight())
		maxX = getRight();
	if (minX < getLeft())
		minX = getLeft();

	// If their projections do not intersect return false
	if (minX > maxX)
		return false;

	// Find corresponding min and max Y for min and max X we found before
	float minY = end1.y;
	float maxY = end2.y;

	float dx = end2.x - end1.x;
	if (fabsf(dx) > 0.0000001f)
	{
		float a = (end2.y - end1.y) / dx;
		float b = end1.y - a * end1.x;
		minY = (a * minX) + b;
		maxY = (a * maxX) + b;
	}
	if (minY > maxY)
	{
		float tmp = maxY;
		maxY = minY;
		minY = tmp;
	}

	// Find the intersection of the segment's and rectangle's y-projections
	if (maxY > getBottom())
		maxY = getBottom();
	if (minY < getTop())
		minY = getTop();

	// If Y-projections do not intersect return false
	if (minY > maxY)
		return false;

	return true;
}

