#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
using std::vector;
#include <Trackable.h>
#include <Timer.h>

#include "Rect.h"
#include "Sprite.h"

class GraphicsBuffer;

enum AnimationPlayMode { PLAYMODE_ONCE, PLAYMODE_LOOP, PLAYMODE_REVERSE, PLAYMODE_REVERSE_LOOP, PLAYMODE_STOP };

class Animation : public Trackable
{
public:
	static const int DEFAULT_MS_PER_FRAME = 100;

	Animation() { resetDataMembers(); }
	Animation(AnimationPlayMode playMode, double msPerFrame);
	Animation(const Animation &ref);
	~Animation() { clearSprites(); }

	//void addSprite(GraphicsBuffer *buffer) { mSpriteList.push_back(new Sprite(buffer)); }
	//void addSprite(GraphicsBuffer *buffer, Rect location) { mSpriteList.push_back(new Sprite(buffer, location)); }
	void addSprite(Sprite *sprite) { mSpriteList.push_back(sprite); }
	void addSprite(const vector<Sprite*> &spriteVector);
	void clearSprites();

	void update();

	Sprite* getCurrentSprite() { return mSpriteList[mPositionInList]; }
	void setMSPerFrame(double msPerFrame);
	double getMSPerFrame() { return mMSPerFrame; }

protected:
	void resetDataMembers();

	vector<Sprite*> mSpriteList;
	AnimationPlayMode mPlayMode;
	Timer mTimer;
	double mMSPerFrame;
	int mPositionInList;
	int mPositionChange;
	bool mTimerStarted;
};

#endif