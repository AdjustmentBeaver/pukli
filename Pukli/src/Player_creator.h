#ifndef __PLAYER_CREATOR__
#define __PLAYER_CREATOR__

#include "Game_object_factory.h"
#include "Player.h"

class PlayerCreator : public Base_creator 
{ 
	Game_object* createGameObject() const  
	{ 
		return new Player(); 
	} 
};

#endif