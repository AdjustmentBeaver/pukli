#ifndef __MENU_STATE_H__
#define __MENU_STATE_H__

#include <vector>
#include "Game_state.h"
#include "Game_object.h"

class Menu_state : public Game_state {
public:
	void update();
	void render();

	bool onEnter();
	bool onExit();

	const std::string get_state_id() const { return s_menu_id; };
private:
	static const std::string s_menu_id;
	std::vector<Game_object*> m_game_objects;
};

#endif