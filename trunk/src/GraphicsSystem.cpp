#include "GraphicsSystem.h"
#include "Services.h"


GraphicsSystem::GraphicsSystem()
{
	mIsInitialized = false;
}

GraphicsSystem::~GraphicsSystem()
{
	cleanup();
}

bool GraphicsSystem::init(const std::string& displayTitle, int displayWidth, int displayHeight)
{
	if (mIsInitialized)
		return false;

	// Set width & height
	mWidth = displayWidth;
	mHeight = displayHeight;

	// Init SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	
	// Setup Window
	mpSDLWindow = SDL_CreateWindow(displayTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mWidth, mHeight, SDL_WINDOW_SHOWN);

	// Create Renderer
	mpSDLRenderer = SDL_CreateRenderer(mpSDLWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	// Init Font
	TTF_Init();

	mpFont = new Font("../assets/porky.ttf", 16);

	// Mark as Inited
	mIsInitialized = true;
	return true;
}

void GraphicsSystem::cleanup()
{
	if (mIsInitialized)
	{
		SDL_DestroyTexture(mpSDLTexture);
		delete mpFont;
		SDL_DestroyRenderer(mpSDLRenderer);
		SDL_DestroyWindow(mpSDLWindow);
		SDL_Quit();
		mIsInitialized = false;
	}
}

// Clear the display to a single color.
void GraphicsSystem::clearToColor(Color& color)
{
	// Sets the color on the renderer & fills it with the color
	SDL_SetRenderDrawColor(mpSDLRenderer, color.getR(), color.getG(), color.getB(), color.getA());
	SDL_RenderFillRect(mpSDLRenderer, NULL);
}

// Swap the display buffers.
void GraphicsSystem::flipDisplay()
{
	// Update and draw to the screen
	SDL_RenderPresent(mpSDLRenderer);

	// Clear the renderer.
	SDL_RenderClear(mpSDLRenderer);
}


void GraphicsSystem::drawTexture(const Texture* pTexture, float x, float y, FlagType flag)
{
	// Coverts the SDL_Surface from the texture to an SDL_Texture so it can be drawn.
	mpSDLTexture = SDL_CreateTextureFromSurface(mpSDLRenderer, pTexture->mpSurface);

	// Get width & height from the texture withquerytexture
	int width, height;
	SDL_QueryTexture(mpSDLTexture, NULL, NULL, &width, &height);

	// Set location by making an SDL_Rect
	SDL_Rect dest{ x,
		y,
		width,
		height };

	// Render texture to screen
	SDL_RenderCopyEx(mpSDLRenderer, mpSDLTexture, NULL, &dest, NULL, NULL, (SDL_RendererFlip)flag);

	// Destory the used texture so it can be reused
	// WARNING: If not destroyed, will cause a memory leak.
	SDL_DestroyTexture(mpSDLTexture);
}

void GraphicsSystem::drawTexture(const Texture* pTexture, Vector2f& location, FlagType flag)
{
	// Coverts the SDL_Surface from the texture to an SDL_Texture so it can be drawn.
	mpSDLTexture = SDL_CreateTextureFromSurface(mpSDLRenderer, pTexture->mpSurface);

	// Get width & height from the texture withquerytexture
	int width, height;
	SDL_QueryTexture(mpSDLTexture, NULL, NULL, &width, &height);

	// Set location by making an SDL_Rect
	SDL_Rect dest{ location.getX(),
		location.getY(),
		width,
		height };

	// Render texture to screen
	SDL_RenderCopyEx(mpSDLRenderer, mpSDLTexture, NULL, &dest, NULL, NULL, (SDL_RendererFlip)flag);

	// Destory the used texture so it can be reused
	// WARNING: If not destroyed, will cause a memory leak.
	SDL_DestroyTexture(mpSDLTexture);
}

void GraphicsSystem::drawSprite(const Sprite& sprite, const Rect& rect, FlagType flag)
{
	// Converts sprite source X, Y, width, and height into an SDL_Rect
	SDL_Rect src{ sprite.getSourceX(),
				  sprite.getSourceY(),
				  sprite.getWidth(),
				  sprite.getHeight() };

	// Converts the destination X, Y, width, and height into an SDL_Rect
	SDL_Rect dest{ rect.getX(),
				   rect.getY(),
				   rect.getWidth(),
				   rect.getHeight() };

	// Coverts the SDL_Surface from the sprite into an SDL_Texture so it can be drawn.
	mpSDLTexture = SDL_CreateTextureFromSurface(mpSDLRenderer, sprite.getTexture()->mpSurface);

	// Render texture to screen
	SDL_RenderCopyEx(mpSDLRenderer, mpSDLTexture, &src, &dest, NULL, NULL, (SDL_RendererFlip)flag);

	// Destory the used texture so it can be reused
	// WARNING: If not destroyed, will cause a memory leak.
	SDL_DestroyTexture(mpSDLTexture);
}

void GraphicsSystem::drawColoredSprite(const Sprite& sprite, const Rect& rect, Color& color, FlagType flag)
{
	// Converts sprite source X, Y, width, and height into an SDL_Rect
	SDL_Rect src{ sprite.getSourceX(),
		sprite.getSourceY(),
		sprite.getWidth(),
		sprite.getHeight() };

	// Converts the destination X, Y, width, and height into an SDL_Rect
	SDL_Rect dest{ rect.getX(),
		rect.getY(),
		rect.getWidth(),
		rect.getHeight() };

	// Coverts the SDL_Surface from the sprite into an SDL_Texture so it can be drawn.
	mpSDLTexture = SDL_CreateTextureFromSurface(mpSDLRenderer, sprite.getTexture()->mpSurface);

	// Change colors & alpha
	SDL_SetTextureColorMod(mpSDLTexture, color.getR(), color.getG(), color.getB());
	SDL_SetTextureAlphaMod(mpSDLTexture, color.getA());

	// Render texture to screen
	SDL_RenderCopyEx(mpSDLRenderer, mpSDLTexture, &src, &dest, NULL, NULL, (SDL_RendererFlip)flag);

	// Destory the used texture so it can be reused
	// WARNING: If not destroyed, will cause a memory leak.
	SDL_DestroyTexture(mpSDLTexture);
}

void GraphicsSystem::writeText(const std::string& message, Color& color, Vector2f& location, int size, FlagType flag)
{
	// Convert color to SDL_Color
	SDL_Color fontColor{ color.getR(),
						 color.getG(),
						 color.getB(),
						 color.getA() };

	// Set size
	mpFont->setSize(size);

	// Render text surface
	mpFont->mpTextSurface = TTF_RenderText_Solid(mpFont->mpFont, message.c_str(), fontColor);

	// Create texture from surface
	mpSDLTexture = SDL_CreateTextureFromSurface(mpSDLRenderer, mpFont->mpTextSurface);

	// Get width & height from the texture withquerytexture
	int width, height;
	SDL_QueryTexture(mpSDLTexture, NULL, NULL, &width, &height);

	// Set location by making an SDL_Rect
	SDL_Rect dest{ location.getX(),
				   location.getY(),
				   width,
				   height };

	// Render texture to screen
	SDL_RenderCopyEx(mpSDLRenderer, mpSDLTexture, NULL, &dest, NULL, NULL, (SDL_RendererFlip)flag);

	// Destory the used texture so it can be reused
	// WARNING: If not destroyed, will cause a memory leak.
	SDL_FreeSurface(mpFont->mpTextSurface); // Helping??? i think.........
	SDL_DestroyTexture(mpSDLTexture);
}

void GraphicsSystem::writeText(const std::string& message, Color& color, int x, int y, int size, FlagType flag)
{
	// Convert color to SDL_Color
	SDL_Color fontColor{ color.getR(),
		color.getG(),
		color.getB(),
		color.getA() };

	// Set size
	mpFont->setSize(size);

	// Render text surface
	mpFont->mpTextSurface = TTF_RenderText_Solid(mpFont->mpFont, message.c_str(), fontColor);

	// Create texture from surface
	mpSDLTexture = SDL_CreateTextureFromSurface(mpSDLRenderer, mpFont->mpTextSurface);

	// Get width & height from the texture withquerytexture
	int width, height;
	SDL_QueryTexture(mpSDLTexture, NULL, NULL, &width, &height);

	// Set location by making an SDL_Rect
	SDL_Rect dest{ x,
		y,
		width,
		height };

	// Render texture to screen
	SDL_RenderCopyEx(mpSDLRenderer, mpSDLTexture, NULL, &dest, NULL, NULL, (SDL_RendererFlip)flag);

	// Destory the used texture so it can be reused
	// WARNING: If not destroyed, will cause a memory leak.
	SDL_DestroyTexture(mpSDLTexture);
}