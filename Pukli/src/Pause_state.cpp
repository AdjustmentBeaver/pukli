#include "Pause_state.h"
#include "Main_menu_state.h"
#include "Play_state.h"
#include "Menu_button.h"
#include "utils.h"
#include "Game.h"
#include "Texture_manager.h"
#include "Input_handler.h"
#include "State_parser.h"

const std::string Pause_state::s_pause_id = "PAUSE";

void Pause_state::update() {
	for (std::vector<Game_object*>::size_type i = 0; The_Game->get_state_machine()->get_current_state() == this && i < m_game_objects.size(); i++) {
		m_game_objects[i]->update();
	}
}
void Pause_state::render() {
	for (std::vector<Game_object*>::size_type i = 0; The_Game->get_state_machine()->get_current_state() == this && i < m_game_objects.size(); i++) {
		m_game_objects[i]->draw();
	}
}

bool Pause_state::on_enter() {
	State_parser state_parser;
	state_parser.parse_state("../config/states.json", s_pause_id, &m_game_objects, &m_texture_ids);

	m_callbacks.push_back(pause_to_play);
	m_callbacks.push_back(pause_to_menu);
	set_callbacks(m_callbacks);

	LOG << "entering Pause_state";
	return true;
}
bool Pause_state::on_exit() {
	LOG << "exiting Pause_state";
	for (std::vector<std::string>::size_type i = 0; i < m_texture_ids.size(); i++) {
		The_Texture_manager->clear_from_texture_map(m_texture_ids[i]);
	}
	for (std::vector<Game_object*>::size_type i = 0; i < m_game_objects.size(); i++) {
		m_game_objects[i]->clean();
		//delete m_game_objects[i];
	}
	m_game_objects.clear();

	The_Input_handler->reset_mouse();

	return true;
}

void Pause_state::pause_to_menu() {
	The_Game->get_state_machine()->clear();
	The_Game->get_state_machine()->change_state(new Main_menu_state());
	LOG << "Back to main menu";
}

void Pause_state::pause_to_play() {
	The_Game->get_state_machine()->pop_state();
	LOG << "Back to game";
}

Pause_state::~Pause_state() {}

void Pause_state::set_callbacks(const std::vector<Callback>& callbacks) {
	// go through the game objects
	for (std::vector<Game_object*>::size_type i = 0; i < m_game_objects.size(); i++) {
		if (dynamic_cast<Menu_button*>(m_game_objects[i])) {
			Menu_button* p_Button = dynamic_cast<Menu_button*>(m_game_objects[i]);
			p_Button->set_callback(callbacks[p_Button->get_callback_id()]);
		}
	}
}
