#include "Animated_graphic.h"
#include <SDL.h>

void Animated_graphic::update() {
	m_current_frame = int((SDL_GetTicks() / (1000 / m_anim_speed)) % m_num_frames);
	SDL_Game_object::update();
}
