#include "Menu_state.h"
#include "Menu_button.h"
#include "utils.h"
#include "Game.h"
#include "Texture_manager.h"

const std::string Menu_state::s_menu_id = "MENU";

void Menu_state::update() {
	for (std::vector<Game_object*>::const_iterator i = m_game_objects.begin(); i != m_game_objects.end(); i++) {
		(*i)->update();
	}
}
void Menu_state::render() {
	for (std::vector<Game_object*>::const_iterator i = m_game_objects.begin(); i != m_game_objects.end(); i++) {
		(*i)->draw();
	}
}

bool Menu_state::on_enter() {
	LOG << "entering Menu_state";

	if (!The_Texture_manager->load("../assets/btn_start.png", "btn_start", The_Game->get_renderer()))
		return false;
	if (!The_Texture_manager->load("../assets/btn_exit.png", "btn_exit", The_Game->get_renderer()))
		return false;

	Game_object* btn_start = new Menu_button(new Loader_params(100, 100, 150, 50, "btn_start"),0);
	Game_object* btn_exit = new Menu_button(new Loader_params(100, 155, 150, 50, "btn_exit"),0);

	m_game_objects.push_back(btn_start);
	m_game_objects.push_back(btn_exit);

	return true;
}
bool Menu_state::on_exit() {
	LOG << "exiting Menu_state";

	for (std::vector<Game_object*>::const_iterator i = m_game_objects.begin(); i != m_game_objects.end(); i++) {
		(*i)->clean();
	}
	m_game_objects.clear();
	The_Texture_manager->clear_from_texture_map("btn_start");
	The_Texture_manager->clear_from_texture_map("btn_exit");

	return true;
}

void Menu_state::menu_to_play() {
	LOG << "Play btn pressed";
}

void Menu_state::menu_to_exit() {
	LOG << "Exit btn pressed";
	The_Game->quit();
}
