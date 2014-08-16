#ifndef __MENU_STATE_H__
#define __MENU_STATE_H__

#include <vector>
#include "Game_state.h"
class Game_object;

class Menu_state : public Game_state {
public:
	void update();
	void render();

	bool on_enter();
	bool on_exit();

	const std::string get_state_id() const { return s_menu_id; };
	~Menu_state();
private:
	static const std::string s_menu_id;
	std::vector<Game_object*> m_game_objects;

	static void menu_to_play();
	static void menu_to_exit();
};

#endif