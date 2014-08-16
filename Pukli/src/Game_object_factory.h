#ifndef __GAME_OBJECT_FACTORY_H__
#define __GAME_OBJECT_FACTORY_H__

#include <map>
#include <string> 
#include <iostream>
#include "Game_object.h"

class Base_creator {
public:
	virtual Game_object* create_game_object() const = 0;
	virtual ~Base_creator() {}
};

class Game_object_factory {
public:
	// Singleton
	static Game_object_factory* instance() {
		if (s_instance == 0)
			s_instance = new Game_object_factory();
		return s_instance;
	}
	
	bool registerType(std::string typeID, Base_creator* pCreator);
	Game_object* create(std::string typeID);
private:
	//Singleton
	Game_object_factory() {}
	static Game_object_factory* s_instance;

	std::map<std::string, Base_creator*> m_creators;
};

#define The_Game_object_factory Game_object_factory::instance()

#endif