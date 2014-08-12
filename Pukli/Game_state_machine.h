#ifndef __GAME_STATE_MACHINE_H__
#define __GAME_STATE_MACHINE_H__

#include "Game_state.h"
#include <vector>

class Game_state_machine {
public:
	void push_state(Game_state* state);
	void pop_state();
	void change_state(Game_state* state);

	void update();
	void render();
private:
	std::vector<Game_state*> m_states;
};

#endif
