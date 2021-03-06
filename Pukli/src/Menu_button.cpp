#include "Menu_button.h"
#include "Input_handler.h"

void Menu_button::draw() {
	SDL_Game_object::draw();
}

void Menu_button::update() {
	Vec2D* mouse_pos = The_Input_handler->get_mouse_position();
	double mx = mouse_pos->get_x();
	double my = mouse_pos->get_y();
	double x = m_position.get_x();
	double y = m_position.get_y();

	if (mx < (x + m_width) && mx >= x && my < (y + m_height) && my >= y) {
		if (The_Input_handler->get_mouse_button_state(LEFT) && m_released) {
			m_current_frame = CLICKED;
			m_callback();
			m_released = false;
		} else if (!The_Input_handler->get_mouse_button_state(LEFT)) {
			m_released = true;
			m_current_frame = MOUSE_OVER;
		}
	} else {
		m_current_frame = MOUSE_OUT;
	}
}

void Menu_button::clean() {
	SDL_Game_object::clean();
}

void Menu_button::load(const Loader_params *pParams){
	m_callback_id = pParams->get_callback_id();
	m_current_frame = MOUSE_OUT;
	SDL_Game_object::load(pParams);
}