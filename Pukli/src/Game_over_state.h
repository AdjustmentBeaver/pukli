#ifndef __GAME_OVER_STATE_H__
#define __GAME_OVER_STATE_H__

#include <vector>
#include "Game_state.h"
class Game_object;

class Game_over_state : public Game_state {
public:
	void update();
	void render();

	bool on_enter();
	bool on_exit();
	~Game_over_state();

	const std::string get_state_id() const { return s_game_over_id; };
private:
	static const std::string s_game_over_id;
	std::vector<Game_object*> m_game_objects;

	static void game_over_to_main();
	static void game_over_to_play();
};

#endif