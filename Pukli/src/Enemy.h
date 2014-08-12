#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "SDL_Game_object.h"

class Enemy : public SDL_Game_object {
public:
	Enemy(const Loader_params* params);
	void update();
	void draw();
	void clean();
	~Enemy() {}
};

#endif // !__ENEMY_H__
