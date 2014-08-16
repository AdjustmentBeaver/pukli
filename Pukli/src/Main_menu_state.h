#ifndef __MAIN_MENU_STATE_H__
#define __MAIN_MENU_STATE_H__

#include <vector>
#include "Menu_state.h"
class Game_object;

typedef void(*Callback)();

class Main_menu_state : public Menu_state {
public:
	void update();
	void render();

	bool on_enter();
	bool on_exit();

	const std::string get_state_id() const { return s_menu_id; };

	void set_callbacks(const std::vector<Callback>& callbacks);

	~Main_menu_state();
private:
	static const std::string s_menu_id;
	std::vector<Game_object*> m_game_objects;

	static void menu_to_play();
	static void menu_to_exit();
};

#endif