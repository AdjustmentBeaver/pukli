#ifndef __GAME_OVER_STATE_H__
#define __GAME_OVER_STATE_H__

#include <vector>
#include "Menu_state.h"
class Game_object;

class Game_over_state : public Menu_state {
public:
	void update();
	void render();

	bool on_enter();
	bool on_exit();
	~Game_over_state();

	const std::string get_state_id() const { return s_game_over_id; };
	void set_callbacks(const std::vector<Callback>& callbacks);
private:
	static const std::string s_game_over_id;
	std::vector<std::string> m_texture_ids;
	std::vector<Game_object*> m_game_objects;
	std::vector<std::string> m_texture_ids;


	static void game_over_to_main();
	static void game_over_to_play();
};

#endif