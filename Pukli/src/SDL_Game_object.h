#ifndef __SDL_GAME_OBJECT__
#define __SDL_GAME_OBJECT__

#include "Vec2D.h"
#include "Game_object.h"

class SDL_Game_object : public Game_object {
public:
	SDL_Game_object(const Loader_params* params);
	
	void update();
	void draw();
	void clean();
	void load(const Loader_params* params);

protected:
	Vec2D m_position;
	Vec2D m_velocity;
	Vec2D m_acceleration;
	int m_width;
	int m_height;
	int m_current_row;
	int m_current_frame;
	std::string m_texture_id;
};

#endif