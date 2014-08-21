#ifndef __INPUT_HANDLER_H_
#define __INPUT_HANDLER_H_

#include <vector>
#include <algorithm>
#include <SDL.h>
#include "Vec2D.h"
#include "utils.h"

#define SDL_BUTTONS_SIZE 4

const enum MOUSE_BUTTONS {LEFT=1, MIDDLE=2, RIGHT=3};
const Sint16 joystick_deadzone = 5000;

class Input_handler {
public:
	// Singleton
	static Input_handler* instance() {
		if (s_instance == 0)
			s_instance = new Input_handler();
		return s_instance;
	}

	// Game loop functions
	void update();
	void clean();

	// Keyboard functions
	bool is_key_down(SDL_Scancode key) { return (m_kbd_key_states && m_kbd_key_states[key]) ? true : false; }

	// Mouse functions
	Vec2D* get_mouse_position() const { return m_mouse_position; }
	bool get_mouse_button_state(int button) { return m_mouse_button_states[button]; }
	void reset_mouse() { std::for_each(m_mouse_button_states.begin(), m_mouse_button_states.end(), [](bool b) {b = false;}); };

	// Joystick functions
	bool init_joysticks();
	bool joysticks_initialized() { return m_joysticks_initialized; }
	bool get_joy_button_state(SDL_JoystickID joy, int btn) { return m_joy_button_states[joy][btn]; }
	int get_joy_x_val(SDL_JoystickID joy, int stick);
	int get_joy_y_val(SDL_JoystickID joy, int stick);

private:
	// Singleton
	Input_handler() :m_mouse_button_states(SDL_BUTTONS_SIZE, false), m_mouse_position(new Vec2D(0, 0)) {}
	static Input_handler* s_instance;
	
	// Keyboard data & functions
	const Uint8* m_kbd_key_states;

	// Mouse data & functions
	Vec2D* m_mouse_position;
	std::vector<bool> m_mouse_button_states;
	
	// Joystick data & functions
	std::vector<SDL_Joystick*> m_joysticks;
	std::vector<std::pair<Vec2D*, Vec2D*>> m_joystick_values;
	std::vector<std::vector<bool>> m_joy_button_states;
	bool m_joysticks_initialized;

	// Keyboard events
	void on_key_up();
	void on_key_down();

	// Mouse events
	void on_mouse_move(SDL_Event& event);
	void on_mouse_btn_up(SDL_Event& event);
	void on_mouse_btn_down(SDL_Event& event);

	// Joystick events
	void on_joystick_axis_move(SDL_Event& event);
	void on_joystick_button_up(SDL_Event& event);
	void on_joystick_button_down(SDL_Event& event);
};

#define The_Input_handler Input_handler::instance()

#endif