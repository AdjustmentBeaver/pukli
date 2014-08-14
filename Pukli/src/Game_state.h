#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include <string>

class Game_state {
public:
	virtual void update() = 0;
	virtual void render() = 0;

	virtual bool on_enter() = 0;
	virtual bool on_exit() = 0;

	virtual const std::string get_state_id() const = 0;

	virtual ~Game_state() {}
};

#endif