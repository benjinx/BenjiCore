#ifndef RECT_H
#define RECT_H

#include "Trackable.h"
#include "Vector2f.h"


// 2D floating-point rectangle.
class Rect : public Trackable
{
public:
	Rect(float x, float y, float width, float height);
	Rect(const Vector2f& position, const Vector2f& size);
	Rect() { reset(); }
	~Rect() {};

	// Accssors
	inline const Vector2f& getSize()		const { return mSize; }
	inline const Vector2f& getPosition()	const { return mPosition; }
	inline float getX()						const { return mPosition.x; }
	inline float getY()						const { return mPosition.y; }
	inline float getWidth()					const { return mSize.x; }
	inline float getHeight()				const { return mSize.y; }
	inline float getArea()					const { return (mSize.x * mSize.y); }
	void inflate(float amount);
	void inflate(float amountX, float amountY);

	// Accessors for Collision
	inline float	getLeft()			const { return mPosition.x; }
	inline float	getRight()			const { return mPosition.x + mSize.x; }
	inline float	getTop()			const { return mPosition.y; }
	inline float	getBottom()			const { return mPosition.y + mSize.y; }
	inline Vector2f	getTopLeft()		const { return mPosition; }
	inline Vector2f	getTopRight()		const { return Vector2f(mPosition.x + mSize.x, mPosition.y); }
	inline Vector2f	getBottomLeft()		const { return Vector2f(mPosition.x, mPosition.y + mSize.y); }
	inline Vector2f	getBottomRight()	const { return mPosition + mSize; }
	inline Vector2f	getCenter()			const { return mPosition + (mSize * 0.5f); }

	// Mutators
	void set(float x, float y, float width, float height);
	inline void setX(float x)							{ mPosition.x = x; }
	inline void setY(float y)							{ mPosition.y = y; }
	inline void setPosition(float x, float y)			{ mPosition.set(x, y); }
	inline void setPosition(const Vector2f& position)	{ mPosition = position; }
	inline void setWidth(float width)					{ mSize.x = width; }
	inline void setHeight(float height)					{ mSize.y = height; }
	inline void setSize(float width, float height)		{ mSize.set(width, height); }
	inline void setSize(const Vector2f& size)			{ mSize = size; }
	inline void reset()									{ set(0.0f, 0.0f, 0.0f, 0.0f); }

	// Intersection
	bool contains(const Vector2f& point) const;
	bool intersects(const Rect& other) const;
	bool intersectsSegment(const Vector2f& end1, const Vector2f& end2) const;


private:
	Vector2f mPosition, mSize;
};


#endif // RECT_H