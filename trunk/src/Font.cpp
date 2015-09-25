#include "Font.h"

Font::Font(const std::string& path, int size)
{
	mpTextSurface = NULL;
	mpFont = TTF_OpenFont(path.c_str(), size);
	mSize = size;
	mPath = path;
}

Font::~Font()
{
	//SDL_FreeSurface(mpTextSurface);
	TTF_CloseFont(mpFont);
	TTF_Quit();
}