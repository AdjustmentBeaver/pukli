#include "Enemy.h"

Enemy::Enemy(const Loader_params* params) : SDL_Game_object(params) {
	m_velocity = Vec2D(0.01,2);
}

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

void Enemy::clean() {}