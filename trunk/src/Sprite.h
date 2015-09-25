#ifndef SPRITE_H
#define SPRITE_H

#include "Vector2f.h"
#include "Rect.h"

class Texture;


// Sprite: a portion of an image.
class Sprite : public Trackable
{
public:
	Sprite();
	Sprite(Texture* pTexture, const Rect& sourceRect, const Vector2f& origin = Vector2f::ZERO);
	Sprite(Texture* pTexture, float sourceX, float sourceY, float width, float height, float originX = 0.0f, float originY = 0.0f);
	Sprite(Texture* pTexture, float originX = 0.0f, float originY = 0.0f);

	void init(Texture* pTexture, float sourceX, float sourceY, float width, float height, float originX = 0.0f, float originY = 0.0f);

	// Accessors
	inline Texture*			getTexture()		const { return mpTexture; }
	inline float			getSourceX()		const { return mSourceRect.getX(); }
	inline float			getSourceY()		const { return mSourceRect.getY(); }
	inline float			getWidth()			const { return mSourceRect.getWidth(); }
	inline float			getHeight()			const { return mSourceRect.getHeight(); }
	inline const Vector2f&	getOrigin()			const { return mOrigin; }
	inline float			getOriginX()		const { return mOrigin.x; }
	inline float			getOriginY()		const { return mOrigin.y; }

	// Mutators.
	inline void		setTexture(Texture* pTexture)					{ mpTexture = pTexture; }
	inline void		setSourceLocation(float x, float y)				{ mSourceRect.setX(x); mSourceRect.setY(y); }
	inline void		setSourceX(float sourceX)						{ mSourceRect.setX(sourceX); }
	inline void		setSourceY(float sourceY)						{ mSourceRect.setY(sourceY); }
	inline void		setSourceSize(float width, float height)		{ mSourceRect.setWidth(width); mSourceRect.setHeight(height); }
	inline void		setWidth(float width)							{ mSourceRect.setWidth(width); }
	inline void		setHeight(float height)							{ mSourceRect.setHeight(height); }
	inline void		setOrigin(const Vector2f& origin)				{ mOrigin = origin; }
	inline void		setOrigin(float x, float y)						{ mOrigin.set(x, y); }
	inline void		centerOrigin()									{ mOrigin.x = mSourceRect.getX() * 0.5f; mOrigin.y = mSourceRect.getY() * 0.5f; }

private:
	Texture*	mpTexture;
	Vector2f	mOrigin;
	Rect mSourceRect;
};


#endif