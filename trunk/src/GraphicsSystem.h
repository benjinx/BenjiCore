#ifndef GRAPHICS_SYSTEM_H
#define GRAPHICS_SYSTEM_H

#include "SDL_Headers.h"
#include <string>
#include "Color.h"
#include "Sprite.h"
#include "Texture.h"
#include "Font.h"
#include "Rect.h"

enum FlagType
{
	FLIP_NONE = SDL_FLIP_NONE,
	FLIP_HORIZONTAL = SDL_FLIP_HORIZONTAL,
	FLIP_VERTICAL = SDL_FLIP_VERTICAL
};

class GraphicsSystem : public Trackable
{
public:
	GraphicsSystem();
	~GraphicsSystem();

	// Accessors
	int getHeight() { return mHeight; }
	int getWidth()	{ return mWidth; }

	// Control functions
	bool init(const std::string& displayTitle, int displayWidth, int displayHeight);
	void cleanup();
	void clearToColor(Color& color);
	void flipDisplay();

	// Sprites & Textures
	void drawTexture(const Texture* pTexture, float x, float y, FlagType flag = FLIP_NONE);
	void drawTexture(const Texture* pTexture, Vector2f& location, FlagType flag = FLIP_NONE);
	void drawSprite(const Sprite& sprite, const Rect& rect, FlagType flag = FLIP_NONE);
	void drawColoredSprite(const Sprite& sprite, const Rect& rect, Color& color, FlagType flag = FLIP_NONE);

	// Text
	void writeText(const std::string& message, Color& color, Vector2f& location, int size = 16, FlagType flag = FLIP_NONE);
	void writeText(const std::string& message, Color& color, int x, int y, int size = 16, FlagType flag = FLIP_NONE);

	
	/*void drawTextureDestination(const Texture* pTexture,
		float destX, float destY, float destWidth, float destHeight,
		float originX = 0.0f, float originY = 0.0f, const Color& color = Color::WHITE, int flags = 0);
	void drawTextureRegion(const Texture* pTexture,
		float sourceX, float sourceY, float sourceWidth, float sourceHeight,
		float destX, float destY, float destWidth, float destHeight,
		float originX = 0.0f, float originY = 0.0f, const Color& color = Color::WHITE, int flags = 0, float scale = 1.0f);

	// Geometry
	void drawLine(const Vector2f& end1, const Vector2f& end2, const Color& color);
	void fillRect(const Rect& rect, const Color& color);
	void drawRect(const Rect& rect, const Color& color);*/

private:
	SDL_Window*	mpSDLWindow;
	SDL_Renderer* mpSDLRenderer;
	Font* mpFont;
	SDL_Texture* mpSDLTexture;
	int	mWidth, mHeight;
	bool mIsInitialized;
};

#endif*/