#ifndef __ANIMATED_GRAPHIC_H__
#define __ANIMATED_GRAPHIC_H__

#include "SDL_Game_object.h"

class Animated_graphic : public SDL_Game_object {
	Animated_graphic(const Loader_params* params, int anim_speed) :SDL_Game_object(params), m_anim_speed(anim_speed) {}

	void update();
	void draw();
	void clean();

	~Animated_graphic() {}
private:
	int m_anim_speed;
	int m_num_frames;
};

#endif