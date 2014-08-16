#include "Enemy.h"

void Enemy::draw() {
	SDL_Game_object::draw();
}

void Enemy::update() {
	if (m_position.get_y() <= 0)
		m_velocity.set_y(2);
	else if (m_position.get_y()+m_width>=720)
		m_velocity.set_y(-2);

	SDL_Game_object::update();
}

void Enemy::load(const Loader_params *params)
{
	SDL_Game_object::load(params);
}

void Enemy::clean() {}