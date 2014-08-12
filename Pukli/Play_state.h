#ifndef __PLAY_STATE_H__
#define __PLAY_STATE_H__

#include "Game_state.h"

class Play_state : public Game_state {
public:
	void update();
	void render();

	bool onEnter();
	bool onExit();

	const std::string get_state_id() const { return s_play_id; };
private:
	static const std::string s_play_id;

};

#endif