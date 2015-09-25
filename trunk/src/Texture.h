#ifndef TEXTURE_H
#define TEXTURE_H

#include <Trackable.h>
#include "SDL_Headers.h"
#include "Vector2D.h"

class Texture : public Trackable
{
	friend class GraphicsSystem;
public:
	Texture(){};
	Texture(int width, int height);
	Texture(const std::string& path);
	~Texture();

	// Accessors
	int getWidth()	const { return mWidth; }
	int getHeight()	const { return mHeight; }

private:
	int mWidth, mHeight;
	SDL_Surface* mpSurface;
};


#endif