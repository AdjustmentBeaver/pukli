#include "Game_over_state.h"
#include "Menu_state.h"
#include "Menu_button.h"
#include "Play_state.h"
#include "Game.h"
#include "Texture_manager.h"
#include "Animated_graphic.h"

const std::string Game_over_state::s_game_over_id = "GAME_OVER";

void Game_over_state::game_over_to_main() {
	The_Game->get_state_machine()->clear();
	The_Game->get_state_machine()->change_state(new Menu_state());
}

void Game_over_state::game_over_to_play() {
	The_Game->get_state_machine()->clear();
	The_Game->get_state_machine()->change_state(new Play_state());
}

bool Game_over_state::on_enter() {
	if (!The_Texture_manager->load("../assets/btn_start.png", "btn_restart", The_Game->get_renderer()))
		return false;
	if (!The_Texture_manager->load("../assets/btn_exit.png", "btn_menu", The_Game->get_renderer()))
		return false;

	m_game_objects.push_back(new Menu_button(new Loader_params(100, 100, 200, 200, "btn_restart"), game_over_to_play));
	m_game_objects.push_back(new Menu_button(new Loader_params(100, 500, 150, 50, "btn_menu"), game_over_to_main));

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
