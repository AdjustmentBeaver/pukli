#include "Menu_state.h"
#include "Play_state.h"
#include "Menu_button.h"
#include "utils.h"
#include "Game.h"
#include "Texture_manager.h"

const std::string Menu_state::s_menu_id = "MENU";

void Menu_state::update() {
	for (std::vector<Game_object*>::size_type i = 0; The_Game->get_state_machine()->get_current_state() == this && i < m_game_objects.size(); i++) {
		m_game_objects[i]->update();
	}
}
void Menu_state::render() {
	for (std::vector<Game_object*>::size_type i = 0; The_Game->get_state_machine()->get_current_state() == this && i < m_game_objects.size(); i++) {
		m_game_objects[i]->draw();
	}
}

bool Menu_state::on_enter() {
	LOG << "entering Menu_state";

	if (!The_Texture_manager->load("../assets/btn_start.png", "btn_start", The_Game->get_renderer()))
		return false;
	if (!The_Texture_manager->load("../assets/btn_exit.png", "btn_exit", The_Game->get_renderer()))
		return false;

	m_game_objects.push_back(new Menu_button(new Loader_params(100, 100, 150, 50, "btn_start"), menu_to_play));
	m_game_objects.push_back(new Menu_button(new Loader_params(100, 200, 150, 50, "btn_exit"), menu_to_exit));

	return true;
}
bool Menu_state::on_exit() {
	LOG << "exiting Menu_state";

	for (std::vector<Game_object*>::size_type i = 0; i < m_game_objects.size(); i++) {
		m_game_objects[i]->clean();
		//delete m_game_objects[i];
	}
	m_game_objects.clear();
	The_Texture_manager->clear_from_texture_map("btn_start");
	The_Texture_manager->clear_from_texture_map("btn_exit");

	return true;
}

void Menu_state::menu_to_play() {
	LOG << "Play btn pressed";
	The_Game->get_state_machine()->change_state(new Play_state());
}

void Menu_state::menu_to_exit() {
	LOG << "Exit btn pressed";
	The_Game->get_state_machine()->pop_state();
	The_Game->quit();
}
