#include "Entity.h"
#include "Services.h"


Entity::Entity() :
	mRect(0.0f, 0.0f, 0.0f, 0.0f),
	mIsAlive(false),
	mFlag(FLIP_NONE)
{
}

void Entity::create()
{
	if (!mIsAlive)
	{
		mIsAlive = true;
		onCreate();
	}
}

void Entity::destroy()
{
	if (mIsAlive)
	{
		mIsAlive = false;
		onDestroy();
	}
}

void Entity::update(float timeDelta)
{
	mAnimation.update();
}

void Entity::draw()
{
	// Draw the sprite
	Services::getGraphicsSystem()->drawSprite(*mAnimation.getCurrentSprite(), mRect, (FlagType)mFlag);
}