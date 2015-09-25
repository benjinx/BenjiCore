#include <iostream>

#include "Animation.h"

Animation::Animation(AnimationPlayMode playMode, double msPerFrame)
{
	resetDataMembers();

	mPlayMode = playMode;
	mMSPerFrame = msPerFrame;
}

Animation::Animation(const Animation &ref)
{
	resetDataMembers();

	for each (Sprite* s in ref.mSpriteList)
	{
		mSpriteList.push_back(new Sprite(*s));
	}

	mPlayMode = ref.mPlayMode;
	mTimer = ref.mTimer;
	mMSPerFrame = ref.mMSPerFrame;
}

void Animation::addSprite(const vector<Sprite*> &spriteVector)
{
	for each (Sprite *ps in spriteVector)
	{
		mSpriteList.push_back(ps);
	}
}

void Animation::clearSprites()
{
	for each (Sprite *ps in mSpriteList)
	{
		if (ps != NULL)
		{
			delete ps;
			ps = NULL;
		}
	}

	mSpriteList.clear();

	resetDataMembers();
}

// =======================================================

void Animation::update()
{
	if (!mTimerStarted)
	{
		mTimer.start();
		mTimerStarted = true;
	}

	if (mTimer.getElapsedTime() >= mMSPerFrame)
	{
		mPositionInList += mPositionChange;

		switch (mPlayMode)
		{
		case PLAYMODE_ONCE:
		{
							  if (mPositionInList > static_cast<int>(mSpriteList.size() - 1)) mPositionInList = mSpriteList.size() - 1;
		}
			break;
		case PLAYMODE_LOOP:
		{
							  mPositionInList %= mSpriteList.size();
		}
			break;
		case PLAYMODE_REVERSE:
		{
								 if (mSpriteList.size() > 1)
								 {
									 if (mPositionInList > static_cast<int>(mSpriteList.size() - 1))
									 {
										 mPositionInList = mSpriteList.size() - 2;
										 mPositionChange = -1;
									 }
									 else if (mPositionInList < 0)
									 {
										 mPositionInList = 0;
									 }
								 }
		}
			break;
		case PLAYMODE_REVERSE_LOOP:
		{
									  if (mSpriteList.size() > 1)
									  {
										  if (mPositionInList > static_cast<int>(mSpriteList.size() - 1))
										  {
											  mPositionInList = mSpriteList.size() - 2;
											  mPositionChange = -1;
										  }
										  else if (mPositionInList < 0)
										  {
											  mPositionInList = 1;
											  mPositionChange = 1;
										  }
									  }
		}
			break;
		}

		mTimer.start();
	}
}

// =======================================================

void Animation::setMSPerFrame(double msPerFrame)
{
	if (msPerFrame < 0) msPerFrame = 0;
	mMSPerFrame = msPerFrame;
}

// =======================================================

void Animation::resetDataMembers()
{
	mPlayMode = PLAYMODE_ONCE;
	mMSPerFrame = DEFAULT_MS_PER_FRAME;
	mPositionInList = 0;
	mPositionChange = 1;
	mTimerStarted = false;
}