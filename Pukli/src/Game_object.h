#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include "Loader_params.h"

class Game_object {
public:
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void clean() = 0;
	virtual ~Game_object() {}
protected:
	Game_object(const Loader_params* params) {}
};

#endif