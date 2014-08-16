#include "SDL_Game_object.h"
#include "Texture_manager.h"
#include "Game.h"
#include "Vec2D.h"

void SDL_Game_object::update() {
	m_velocity += m_acceleration;
	m_position += m_velocity;
}

void SDL_Game_object::load(const Loader_params *params) 
{ 
	LOG << "sld_load callin";
	m_position = Vec2D(params->get_x(), params->get_y());  
	m_velocity = Vec2D(0, 0);  
	m_acceleration = Vec2D(0, 0);  
	m_width = params->get_width();  
	m_height = params->get_height(); 
	m_texture_id = params->get_texture_id();
	m_current_row = 0;
	m_current_frame = 0;
	m_num_frames = params->get_num_frames();

	Game_object::load(params);
}

void SDL_Game_object::draw() {
	The_Texture_manager->draw_frame(m_texture_id, round(m_position.get_x()),round(m_position.get_y()), m_width, m_height, m_current_row, m_current_frame, The_Game->get_renderer());
}

void SDL_Game_object::clean() {}
