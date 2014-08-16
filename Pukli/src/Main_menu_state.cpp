#include "Main_menu_state.h"
#include "Play_state.h"
#include "Menu_button.h"
#include "utils.h"
#include "Game.h"
#include "Texture_manager.h"
#include "State_parser.h"

const std::string Main_menu_state::s_menu_id = "MENU";

void Main_menu_state::update() {
	for (std::vector<Game_object*>::size_type i = 0; The_Game->get_state_machine()->get_current_state() == this && i < m_game_objects.size(); i++) {
		m_game_objects[i]->update();
	}
}
void Main_menu_state::render() {
	for (std::vector<Game_object*>::size_type i = 0; The_Game->get_state_machine()->get_current_state() == this && i < m_game_objects.size(); i++) {
		m_game_objects[i]->draw();
	}
}

bool Main_menu_state::on_enter() {
	State_parser state_parser;
	state_parser.parse_state("test.xml", s_menu_id, &m_game_objects, &m_texture_ids);

	m_callbacks.push_back(menu_to_play);
	m_callbacks.push_back(menu_to_exit);
	set_callbacks(m_callbacks);

	LOG << "entering Menu_state";
	return true;
}
bool Main_menu_state::on_exit() {
	LOG << "exiting Menu_state";

	for (std::vector<std::string>::size_type i = 0; i < m_texture_ids.size(); i++) {
		The_Texture_manager->clear_from_texture_map(m_texture_ids[i]);
	}

	return true;
}

void Main_menu_state::menu_to_play() {
	LOG << "Play btn pressed";
	The_Game->get_state_machine()->change_state(new Play_state());
}

void Main_menu_state::menu_to_exit() {
	LOG << "Exit btn pressed";
	The_Game->get_state_machine()->pop_state();
	The_Game->quit();
}

Main_menu_state::~Main_menu_state() {
	for (std::vector<Game_object*>::size_type i = 0; i < m_game_objects.size(); i++) {
		m_game_objects[i]->clean();
		delete m_game_objects[i];
	}
	LOG << "DESTR" << "Main_menu_State";
}

void Main_menu_state::set_callbacks(const std::vector<Callback>& callbacks) {
	// go through the game objects
	for (int i = 0; i < m_game_objects.size(); i++) {
		if (dynamic_cast<Menu_button*>(m_game_objects[i])) {
			Menu_button* p_Button = dynamic_cast<Menu_button*>(m_game_objects[i]);
			p_Button->set_callback(callbacks[p_Button->get_callback_id()]);
		}
	}
}
