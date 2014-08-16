#ifndef __GAME_OBJECT_FACTORY__
#define __GAME_OBJECT_FACTORY__

#include <string> 
#include <map>
#include "Game_object.h"
#include <string.h>
#include <iostream>

class Base_creator {
public:
	virtual Game_object* create_game_object() const = 0; 
	virtual ~Base_creator() {}
};

class Game_object_factory {
public:
	bool registerType(std::string typeID, Base_creator* pCreator)  
	{
		std::map<std::string, Base_creator*>::iterator it = m_creators.find(typeID);
		
		// if the type is already registered, do nothing    
		if(it != m_creators.end())
		{
			//delete pCreator;      
			return false;    
		}
		m_creators[typeID] = pCreator;
		return true;
	}

	Game_object* create(std::string typeID) 
	{
		std::map<std::string, Base_creator*>::iterator it = m_creators.find(typeID);
		if (it == m_creators.end())    
		{
			std::cout << "could not find type: " << typeID << "\n";      
			return NULL; 
		}
		
		Base_creator* pCreator = (*it).second;   
		return pCreator->create_game_object();
	}

	// Singleton
	static Game_object_factory* instance() {
		if (s_instance == 0)
			s_instance = new Game_object_factory();
		return s_instance;
	}
private:
	std::map<std::string, Base_creator*> m_creators;

	//Singleton
	Game_object_factory() {}
	static Game_object_factory* s_instance;
};

#endif