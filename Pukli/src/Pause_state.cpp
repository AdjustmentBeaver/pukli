#include "Pause_state.h"
#include "Menu_state.h"
#include "Play_state.h"
#include "Menu_button.h"
#include "utils.h"
#include "Game.h"
#include "Texture_manager.h"
#include "Input_handler.h"

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
	LOG << "entering Pause_state";

	if (!The_Texture_manager->load("../assets/chain.png", "btn_resume", The_Game->get_renderer()))
		return false;
	if (!The_Texture_manager->load("../assets/soup.bmp", "btn_menu", The_Game->get_renderer()))
		return false;

	m_game_objects.push_back(new Menu_button(new Loader_params(100, 100, 150, 50, "btn_resume"), pause_to_menu));
	m_game_objects.push_back(new Menu_button(new Loader_params(100, 200, 150, 50, "btn_menu"), pause_to_play));

	return true;
}
bool Pause_state::on_exit() {
	LOG << "exiting Pause_state";
	for (std::vector<Game_object*>::size_type i = 0; i < m_game_objects.size(); i++) {
		m_game_objects[i]->clean();
		////delete m_game_objects[i];
	}
	m_game_objects.clear();
	The_Texture_manager->clear_from_texture_map("btn_resume");
	The_Texture_manager->clear_from_texture_map("btn_menu");

	The_Input_handler->reset_mouse();

	return true;
}

void Pause_state::pause_to_menu() {
	The_Game->get_state_machine()->clear();
	The_Game->get_state_machine()->change_state(new Menu_state());
	LOG << "Back to main menu";
}

void Pause_state::pause_to_play() {
	The_Game->get_state_machine()->pop_state();
	LOG << "Back to game";
}

Pause_state::~Pause_state() {
	for (std::vector<Game_object*>::size_type i = 0; i < m_game_objects.size(); i++) {

		delete m_game_objects[i];
	}
}