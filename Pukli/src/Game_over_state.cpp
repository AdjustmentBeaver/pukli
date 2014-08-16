#include "Game_over_state.h"
#include "Main_menu_state.h"
#include "Menu_button.h"
#include "Play_state.h"
#include "Game.h"
#include "Texture_manager.h"
#include "Animated_graphic.h"
#include "State_parser.h"

const std::string Game_over_state::s_game_over_id = "GAME_OVER";

void Game_over_state::game_over_to_main() {
	The_Game->get_state_machine()->clear();
	The_Game->get_state_machine()->change_state(new Main_menu_state());
}

void Game_over_state::game_over_to_play() {
	The_Game->get_state_machine()->clear();
	The_Game->get_state_machine()->change_state(new Play_state());
}

bool Game_over_state::on_enter() {
	State_parser state_parser;
	state_parser.parse_state("../config/states.json", s_game_over_id, &m_game_objects, &m_texture_ids);

	m_callbacks.push_back(game_over_to_main);
	m_callbacks.push_back(game_over_to_play);
	set_callbacks(m_callbacks);

	return true;
}

bool Game_over_state::on_exit() {
	LOG << "exiting game_over_state";

	for (std::vector<std::string>::size_type i = 0; i < m_texture_ids.size(); i++) {
		The_Texture_manager->clear_from_texture_map(m_texture_ids[i]);
	}

	return true;
}
void Game_over_state::update() {
	for (std::vector<Game_object*>::size_type i = 0; The_Game->get_state_machine()->get_current_state() == this && i<m_game_objects.size(); i++) {
		m_game_objects[i]->update();
	}
}
void Game_over_state::render() {
	for (std::vector<Game_object*>::size_type i = 0; The_Game->get_state_machine()->get_current_state() == this && i < m_game_objects.size(); i++) {
		m_game_objects[i]->draw();
	}
}


Game_over_state::~Game_over_state() {
	for (std::vector<Game_object*>::size_type i = 0; i < m_game_objects.size(); i++) {
		m_game_objects[i]->clean();
		delete m_game_objects[i];
	}
}

void Game_over_state::set_callbacks(const std::vector<Callback>& callbacks) {
	// go through the game objects
	for (std::vector<Game_object*>::size_type i = 0; i < m_game_objects.size(); i++) {
		if (dynamic_cast<Menu_button*>(m_game_objects[i])) {
			Menu_button* p_Button = dynamic_cast<Menu_button*>(m_game_objects[i]);
			p_Button->set_callback(callbacks[p_Button->get_callback_id()]);
		}
	}
}
