#ifndef __ENEMY_CREATOR__
#define __ENEMY_CREATOR__

#include "Game_object_factory.h"
#include "Enemy.h"

class Enemy_creator : public Base_creator {
public:
	Enemy_creator() {}

	Game_object* create_game_object() const
	{
		return new Enemy();
	}
};

#endif