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
	state_parser.parse_state("test.xml", s_game_over_id, &m_game_objects, &m_texture_ids);

	m_callbacks.push_back(game_over_to_main);
	m_callbacks.push_back(game_over_to_play);
	set_callbacks(m_callbacks);

	return true;
}

bool Game_over_state::on_exit() {

	for (std::vector<Game_object*>::size_type i = 0; i < m_game_objects.size(); i++) {
		m_game_objects[i]->clean();
		////delete m_game_objects[i];
	}
	m_game_objects.clear();
	The_Texture_manager->clear_from_texture_map("btn_restart");
	The_Texture_manager->clear_from_texture_map("btn_menu");


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

		delete m_game_objects[i];
	}
}