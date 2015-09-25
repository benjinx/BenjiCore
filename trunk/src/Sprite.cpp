#include "Sprite.h"
#include "Texture.h"
#include <assert.h>

Sprite::Sprite()
{
	mpTexture = NULL;
	mSourceRect.set(0, 0, 0, 0);
	mOrigin.setZero();
}

Sprite::Sprite(Texture* pTexture, const Rect& sourceRect, const Vector2f& origin)
{
	mpTexture = pTexture;
	mSourceRect.set(sourceRect.getX(),
					sourceRect.getY(),
					sourceRect.getWidth(),
					sourceRect.getHeight());
	mOrigin = origin;
}

Sprite::Sprite(Texture* pTexture, float sourceX, float sourceY, float width, float height, float originX, float originY)
{
	mpTexture = pTexture;
	mSourceRect.set(sourceX,
					sourceY,
					width,
					height);
	mOrigin.set(originX, originY);
}

Sprite::Sprite(Texture* pTexture, float originX, float originY)
{
	assert(pTexture != NULL);
	mpTexture = pTexture;
	mSourceRect.set(0,
					0,
					(float)pTexture->getWidth(),
					(float)pTexture->getHeight());
	mOrigin.set(originX, originY);
}

void Sprite::init(Texture* pTexture, float sourceX, float sourceY, float width, float height, float originX, float originY)
{
	mpTexture = pTexture;
	mSourceRect.set(sourceX,
					sourceY,
					width,
					height);
	mOrigin.set(originX, originY);
}