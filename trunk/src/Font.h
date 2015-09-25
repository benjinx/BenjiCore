#ifndef FONT_H
#define FONT_H

#include <Trackable.h>
#include "SDL_Headers.h"

class Font : public Trackable
{
	friend class GraphicsSystem;
public:
	Font(const std::string& path, int size);
	~Font();

	// Accessors
	int getSize() { return mSize; }

	// Mutator
	void setSize(int size) { mpFont = TTF_OpenFont(mPath.c_str(), size); mSize = size; }

private:
	SDL_Surface* mpTextSurface;
	TTF_Font* mpFont;
	int mSize;
	std::string mPath;
};
#endif