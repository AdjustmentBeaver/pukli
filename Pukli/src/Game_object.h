#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include "Loader_params.h"
#include "utils.h"

class Game_object {
public:
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void clean() = 0;

	virtual void load(const Loader_params* params) {
		LOG << "deleting";
		delete params;
	}


	virtual ~Game_object() {}
protected:
	Game_object() {}
};

#endif