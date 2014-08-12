#include "Player.h"
#include "Input_handler.h"
#include "Game.h"

Player::Player(const Loader_params* params) : SDL_Game_object(params) {}

void Player::draw() {
	SDL_Game_object::draw();
}

void Player::update() {

	handleInput();

	SDL_Game_object::update();
}

void Player::load(const Loader_params *pParams) 
{
	SDL_Game_object::load(pParams); 
}

void Player::clean() {}

void Player::handleInput() {
	if (The_Input_handler->joysticks_initialized()) {
		double lx = The_Input_handler->get_joy_x_val(0, 1), ly = The_Input_handler->get_joy_y_val(0, 1);
		m_acceleration = Vec2D(lx/10.0,ly/10.0);
	if (The_Input_handler->get_joy_button_state(0,0)) m_velocity = Vec2D();
	}
	
	
	if (The_Input_handler->is_key_down(SDL_SCANCODE_ESCAPE))
		The_Game->quit();

	if (The_Input_handler->is_key_down(SDL_SCANCODE_UP))
		m_velocity.set_y(-2);

	if (The_Input_handler->is_key_down(SDL_SCANCODE_DOWN))
		m_velocity.set_y(2);

	if (The_Input_handler->is_key_down(SDL_SCANCODE_LEFT))
		m_velocity.set_x(-2);

	if (The_Input_handler->is_key_down(SDL_SCANCODE_RIGHT))
		m_velocity.set_x(2);

	//m_velocity = (*The_Input_handler->get_mouse_position() - m_position) / 100;
}
