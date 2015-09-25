#include <iostream>
#include "Game.h"
#include <MemoryTracker.h>

using namespace std;


/*
	TODO: Make Sprite work off a Rect instead of 2 Vector2fs




*/






int main(int argc, char *args[])
{
	// Initialize the game.
	Game::initInstance();
	if (!Game::getInstance()->init())
	{
		Game::cleanupInstance();
		gMemoryTracker.reportAllocations(std::cout);
		system("pause");
		return EXIT_FAILURE;
	}

	// Run the game loop.
	Game::getInstance()->gameLoop();

	// Cleanup the game.
	Game::getInstance()->cleanup();
	Game::cleanupInstance();

	gMemoryTracker.reportAllocations(std::cout);
	system("pause");
	return EXIT_SUCCESS;

	// The Images
	/*SDL_Window* screen = NULL;
	SDL_Renderer* ren = NULL;
	SDL_Texture* tex = NULL;

	// Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// Setup screen
	screen = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

	// Create Renderer
	ren = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// Load Image
	Texture* mpKirby = new Texture("../assets/kirby.png");

	// Apply image to screen
	//tex = SDL_CreateTextureFromSurface(ren, );

	// Update Screen
	SDL_RenderClear(ren);
	SDL_RenderCopy(ren, tex, NULL, NULL);
	SDL_RenderPresent(ren);

	// Pause
	//SDL_Delay(2000);
	system("pause");

	// Cleanup
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(screen);
	SDL_Quit();*/
}