#include "Player.h"
#include "Input_handler.h"
#include "Game.h"
#include "Debug_window.h"

void Player::draw() {
	SDL_Game_object::draw();
}

void Player::update() {

	handleInput();

	SDL_Game_object::update();
}

void Player::load(const Loader_params *params) {
	SDL_Game_object::load(params);
	The_Debug_Watcher->add("player x", m_position.get_x());
	The_Debug_Watcher->add("player y", m_position.get_y());
}

void Player::clean() {
	The_Debug_Watcher->remove("player x");
	The_Debug_Watcher->remove("player y");
}

void Player::handleInput() {
	m_velocity = Vec2D(0, 0);
	if (The_Input_handler->joysticks_initialized()) {
		double lx = The_Input_handler->get_joy_x_val(0, 1), ly = The_Input_handler->get_joy_y_val(0, 1);
		m_acceleration = Vec2D(lx / 10.0, ly / 10.0);
		if (The_Input_handler->get_joy_button_state(0, 0)) m_velocity = Vec2D();
	}
	if (The_Input_handler->is_key_down(SDL_SCANCODE_UP))
		m_velocity.set_y(-2);

	if (The_Input_handler->is_key_down(SDL_SCANCODE_DOWN))
		m_velocity.set_y(2);

	if (The_Input_handler->is_key_down(SDL_SCANCODE_LEFT))
		m_velocity.set_x(-2);

	if (The_Input_handler->is_key_down(SDL_SCANCODE_RIGHT))
		m_velocity.set_x(2);
}

Player::~Player() {}