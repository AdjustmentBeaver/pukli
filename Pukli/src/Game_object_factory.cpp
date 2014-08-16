#include "Game_object_factory.h"

const Game_object_factory::s_instance = 0;

bool Game_object_factory::registerType(std::string typeID, Base_creator* pCreator) {
	std::map<std::string, Base_creator*>::iterator it = m_creators.find(typeID);

	// if the type is already registered, do nothing    
	if (it != m_creators.end()) {
		//delete pCreator;      
		return false;
	}
	m_creators[typeID] = pCreator;
	return true;
}

Game_object* Game_object_factory::create(std::string typeID) {
	std::map<std::string, Base_creator*>::iterator it = m_creators.find(typeID);
	if (it == m_creators.end()) {
		std::cout << "could not find type: " << typeID << "\n";
		return NULL;
	}

	Base_creator* pCreator = (*it).second;
	return pCreator->create_game_object();
}