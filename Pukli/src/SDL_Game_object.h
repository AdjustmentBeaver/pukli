#ifndef __SDL_GAME_OBJECT__
#define __SDL_GAME_OBJECT__

#include "Vec2D.h"
#include "Game_object.h"

class SDL_Game_object : public Game_object {
public:
	SDL_Game_object() {}
	
	void update();
	void draw();
	void clean();
	void load(const Loader_params* params);

	const Vec2D& get_position() const { return m_position; }
	const int get_width() const { return m_width; }
	const int get_height() const { return m_height; }

	~SDL_Game_object() {}
protected:
	Vec2D m_position;
	Vec2D m_velocity;
	Vec2D m_acceleration;
	int m_width;
	int m_height;
	int m_current_row;
	int m_current_frame;
	std::string m_texture_id;
	int m_num_frames;
};

#endif