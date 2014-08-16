#ifndef __PLAY_STATE_H__
#define __PLAY_STATE_H__

#include <vector>
#include "Game_state.h"
#include "SDL_Game_object.h"
class Game_object;

class Play_state : public Game_state {
public:
	void update();
	void render();

	bool on_enter();
	bool on_exit();

	const std::string get_state_id() const { return s_play_id; };
	bool checkCollision(SDL_Game_object* p1, SDL_Game_object* p2);
	~Play_state();
private:
	static const std::string s_play_id;
	std::vector<std::string> m_texture_ids;
	std::vector<Game_object*> m_game_objects;
};

#endif