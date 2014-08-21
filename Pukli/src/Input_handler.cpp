#include <algorithm>
#include "Input_handler.h"
#include "Game.h"
#include "utils.h"

// Singleton
Input_handler* Input_handler::s_instance = 0;

// Game loop functions
void Input_handler::update() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			The_Game->quit();
			break;
		case SDL_JOYAXISMOTION:
			on_joystick_axis_move(event);
			break;
		case SDL_JOYBUTTONDOWN:
			on_joystick_button_down(event);
			break;
		case SDL_JOYBUTTONUP:
			on_joystick_button_up(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			on_mouse_btn_down(event);
			break;
		case SDL_MOUSEBUTTONUP:
			on_mouse_btn_up(event);
			break;
		case SDL_MOUSEMOTION:
			on_mouse_move(event);
			break;
		case SDL_KEYDOWN:
			on_key_down();
			break;
		case SDL_KEYUP:
			on_key_up();
			break;
		default:
			break;
		}
	}
}
void Input_handler::clean() {
	if (m_joysticks_initialized) {
		for (int i = 0; i < SDL_NumJoysticks(); i++) {
			SDL_JoystickClose(m_joysticks[i]);
		}
	}
	//delete m_mouse_position;
	// Using a simple lambda function
	//std::for_each(m_joystick_values.begin(), m_joystick_values.end(), [](std::pair<Vec2D*, Vec2D*> val) {//delete val.first; //delete val.second; });
}

// Joystick functions
bool Input_handler::init_joysticks() {
	m_joysticks_initialized = false;
	if (!SDL_WasInit(SDL_INIT_JOYSTICK))
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);

	if (SDL_NumJoysticks() > 0) {
		for (int i = 0; i < SDL_NumJoysticks(); i++) {
			SDL_Joystick* joy = SDL_JoystickOpen(i);
			if (joy) {
				m_joysticks.push_back(joy);
				m_joystick_values.push_back(std::make_pair(new Vec2D(0, 0), new Vec2D(0, 0)));

				std::vector<bool> tmp_btns;
				for (int j = 0; j < SDL_JoystickNumButtons(joy); j++)
					tmp_btns.push_back(false);
				m_joy_button_states.push_back(tmp_btns);

			} else
				return false;
		}
		SDL_JoystickEventState(SDL_ENABLE);
		m_joysticks_initialized = true;

		LOG << "Joysticks: " << m_joysticks.size();

		return true;
	} else
		return false;
}
int Input_handler::get_joy_x_val(SDL_JoystickID joy, int stick) {
	if (m_joystick_values.size() == 0)
		return 0;
	return stick == 1 ? m_joystick_values[joy].first->get_x() : m_joystick_values[joy].second->get_x();
}
int Input_handler::get_joy_y_val(SDL_JoystickID joy, int stick) {
	if (m_joystick_values.size() == 0)
		return 0;
	return stick == 1 ? m_joystick_values[joy].first->get_y() : m_joystick_values[joy].second->get_y();
}

// Keyboard events
void Input_handler::on_key_up() {
	m_kbd_key_states = SDL_GetKeyboardState(0);
}
void Input_handler::on_key_down() {
	on_key_up();
}

// Mouse events
void Input_handler::on_mouse_move(SDL_Event& event) {
	m_mouse_position->set_x(event.motion.x);
	m_mouse_position->set_y(event.motion.y);
}
void Input_handler::on_mouse_btn_up(SDL_Event& event) {
	m_mouse_button_states[event.button.button] = false;
}
void Input_handler::on_mouse_btn_down(SDL_Event& event) {
	m_mouse_button_states[event.button.button] = true;
}

// Joystick events
void Input_handler::on_joystick_axis_move(SDL_Event& event) {
	void (Vec2D::*setter)(double); // Function pointer for the value setter

	// 0 & 1 -> left stick H,V axis; 3 & 4 -> right stick H,V axis
	bool left_stick = event.jaxis.axis == 0 || event.jaxis.axis == 1;
	LOG << "[INFO] stick:" << left_stick << "axis:" << (int)event.jaxis.axis;
	Vec2D * the_stick = left_stick ? m_joystick_values[event.jaxis.which].first : m_joystick_values[event.jaxis.which].second;

	setter = 0;

	switch (event.jaxis.axis) {
	case 1:
	case 4: // 1 & 4 are the vertical axis Y
		setter = &Vec2D::set_y;
		break;
	case 0:
	case 3: // 0 & 3 & 2 are the horizontal axis X 
		setter = &Vec2D::set_x;
		break;
	default:
		return;
		break;
	}

	LOG << event.jaxis.value;


	// Calling the adequate joystick value setter (set_x/set_y) on the used stick; values(digital) : +1 right, -1 left, 0 middle
	if (event.jaxis.value > joystick_deadzone)
		(the_stick->*setter)(1);
	else if (event.jaxis.value < -joystick_deadzone)
		(the_stick->*setter)(-1);
	else
		(the_stick->*setter)(0);
}
void Input_handler::on_joystick_button_up(SDL_Event& event) {
	m_joy_button_states[event.jaxis.which][event.jbutton.button] = false;
}
void Input_handler::on_joystick_button_down(SDL_Event& event) {
	m_joy_button_states[event.jaxis.which][event.jbutton.button] = true;
}