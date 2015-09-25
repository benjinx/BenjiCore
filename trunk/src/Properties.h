#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <string>

using namespace std;

class Properties
{
public:
	Properties();
	~Properties();

	static const string VERSION;
	const string Properties::VERSION = ".01";

	static int width;

	static int height;

	static int halfWidth;

	static int halfHeight;

	static bool fixed;

	static bool timeInFrames;

	static int frameRate;

	static int assignedFrameRate;

	static int elapsed;

	static int rate;
	int Properties::rate = 1;

	// static Screen screen;

	// static BitmapData buffer;

	// static Rectangle bounds;

	// static Point camera;

	// static Tweener tweener = new Tweener;

	static bool focused;
	bool Properties::focused = true;

};

#endif