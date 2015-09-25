#include "Texture.h"


Texture::Texture(int width, int height)
{
	mWidth = width;
	mHeight = height;
	mpSurface = NULL;
}

Texture::Texture(const std::string& path)
{
	mpSurface = IMG_Load(path.c_str());
	mWidth = mpSurface->w;
	mHeight = mpSurface->h;
}

Texture::~Texture()
{
	SDL_FreeSurface(mpSurface);
}