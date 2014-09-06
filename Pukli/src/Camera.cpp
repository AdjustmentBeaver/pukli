#include "Camera.h"
#include "Game.h"

Vec2D Camera::get_position() const
{
	if (m_target != 0)
	{
		/*
		
		The_Game nincs get_game_width és get_game_height. Máshova kell. 

		Vec2D pos(m_target->get_x - (The_Game->get_game_width() / 2), m_target->get_y - (The_Game->get_game_height() / 2));
		
		*/

		Vec2D pos(m_target->get_x - (800 / 2), m_target->get_y - (600 / 2));
		
		if (pos.get_x< 0)
		{
			pos.get_x = 0;
		}

		if (pos.get_y< 0)
		{
			pos.get_y = 0;
		}
		return pos;
	}

	return m_position;
}