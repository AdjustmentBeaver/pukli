#ifndef __PAUSE_STATE_H__
#define __PAUSE_STATE_H__

#include <vector>
#include "Menu_state.h"
class Game_object;

class Pause_state : public Menu_state {
public:
	void update();
	void render();

	bool on_enter();
	bool on_exit();

	const std::string get_state_id() const { return s_pause_id; };
	void set_callbacks(const std::vector<Callback>& callbacks);

	~Pause_state();
private:
	static const std::string s_pause_id;
	std::vector<Game_object*> m_game_objects;
	std::vector<std::string> m_texture_ids;

	static void pause_to_menu();
	static void pause_to_play();
};

#endif