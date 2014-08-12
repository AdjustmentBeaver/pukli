#include "Enemy.h"

Enemy::Enemy(const Loader_params* params) : SDL_Game_object(params) {}

void Enemy::draw() {
	SDL_Game_object::draw();
}

void Enemy::update() {
	SDL_Game_object::update();
}

void Enemy::clean() {}