#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	//~Player();

	// Virtual methods
	void onCreate() {};
	void onDestroy(){};
	void update(){};
};

#endif