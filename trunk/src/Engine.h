#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
public:
	/*	Constructor - Defines the startup information about your game.
		Width of the game
		Height of the game
		Framerate of the game
		fixed - if a fixed-framerate should be used.
	*/
	Engine(int width, int height, int frameRate = 60, bool fixed = false);
	~Engine();


};

#endif