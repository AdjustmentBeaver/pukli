#ifndef __GAME_OBJECT_FACTORY__
#define __GAME_OBJECT_FACTORY__

#include <string> 
#include <map>
#include "Game_object.h"
#include <iostream>

class Base_creator {
public:
	virtual Game_object* createGameObject() const = 0; 
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
			std::cout << "could not find type: " << typeID << "\n";      return NULL; 
		}
		
		Base_creator* pCreator = (*it).second;    return pCreator->createGameObject();
	}
private:
	std::map<std::string, Base_creator*> m_creators;
};

#endif