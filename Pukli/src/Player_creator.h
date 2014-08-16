#ifndef __PLAYER_CREATOR__
#define __PLAYER_CREATOR__

#include "Game_object_factory.h"
#include "Player.h"

class Player_creator : public Base_creator { 
public:
	Player_creator() {}

	Game_object* create_game_object() const
	{
		return new Player();
	}
};

#endif