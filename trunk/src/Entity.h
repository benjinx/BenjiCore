#ifndef ENTITY_H
#define ENTITY_H

#include <Trackable.h>

#include "Sprite.h"
#include "Animation.h"
#include "Rect.h"

class Entity : public Trackable
{
public:
	Entity();
	~Entity(){};

	// Accessors
	inline const int getX() const { return (int)mRect.getX(); }
	inline const int getY() const { return (int)mRect.getY(); }
	inline const int getWidth() const { return (int)mRect.getWidth(); }
	inline const int getHeight() const { return (int)mRect.getHeight(); }
	inline bool isAlive() const { return mIsAlive; }
	inline bool isDead() const { return !mIsAlive; }

	// Mutators
	inline void setRect(int x, int y, int width, int height) { mRect.setX((float)x); mRect.setY((float)y); mRect.setWidth((float)width); mRect.setHeight((float)height); }
	inline void setPosition(int x, int y) { mRect.setX((float)x); mRect.setY((float)y); }
	inline void setX(int x) { mRect.setX((float)x); }
	inline void setY(int y) { mRect.setY((float)y); }
	inline void setProportions(int width, int height) { mRect.setWidth((float)width); mRect.setHeight((float)height); }
	inline void setWidth(int width) { mRect.setWidth((float)width); }
	inline void setHeight(int height) { mRect.setHeight((float)height); }
	inline void setAnimation(const Animation& animation) { mAnimation = animation; }
	inline void setFlag(int flag) { mFlag = flag; }

	void create();
	void destroy();

	// Virtual methods
	virtual void onCreate() {}
	virtual void onDestroy() {}
	virtual void update(float timeDelta);
	virtual void draw();

protected:
	Rect mRect;
	Animation mAnimation;
	int mFlag;

private:
	bool mIsAlive;
};

#endif