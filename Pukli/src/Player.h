#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "SDL_Game_object.h"

class Player : public SDL_Game_object {
public:
	Player() {}
	void update();
	void draw();
	void clean();
	void load(const Loader_params* params);
	~Player();
private:
	void handleInput();
};

#endif
