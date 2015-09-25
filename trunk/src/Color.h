#ifndef COLOR_H
#define COLOR_H

#include <Trackable.h>

class Color : public Trackable
{
public:
	Color(){};
	Color(int r, int g, int b, int a) :
		mR(r), mG(g), mB(b), mA(a)
	{
	}
	~Color(){};

	// Accessors
	int getR() { return mR; }
	int getG() { return mG; }
	int getB() { return mB; }
	int getA() { return mA; }

	// Mutators
	void setR(int value) { mR = value; }
	void setG(int value) { mG = value; }
	void setB(int value) { mB = value; }
	void setA(int value) { mA = value; }

private:
	int mR, mG, mB, mA;
};

#endif