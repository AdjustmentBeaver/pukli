#include "Main_menu_state.h"
#include "Play_state.h"
#include "Menu_button.h"
#include "utils.h"
#include "Game.h"
#include "Texture_manager.h"

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
	
	//JSON Parse - new stuff
	/*
	
	State_parser state_parser;
	state_parser.parseState("test.xml", s_menuID, &m_gameObjects,&m_textureIDList);

	m_callbacks.push_back(0);
	m_callbacks.push_back(menu_to_play);
	m_callbacks.push_back(menu_to_exit);

	set_callbacks(m_callbacks);

	*/

	if (!The_Texture_manager->load("../assets/btn_start.png", "btn_start", The_Game->get_renderer()))
		return false;
	if (!The_Texture_manager->load("../assets/btn_exit.png", "btn_exit", The_Game->get_renderer()))
		return false;


	m_game_objects.push_back(new Menu_button(new Loader_params(100, 100, 150, 50, "btn_start"), menu_to_play));
	m_game_objects.push_back(new Menu_button(new Loader_params(100, 200, 150, 50, "btn_exit"), menu_to_exit));

	LOG << "entering Menu_state";

	return true;
}
bool Main_menu_state::on_exit() {
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

		delete m_game_objects[i];
	}
	LOG << "DESTR" << "Main_menu_State";
}

void Main_menu_state::set_callbacks(const std::vector<Callback>& callbacks)
{
	// go through the game objects
	for (int i = 0; i < m_game_objects.size(); i++)
	{
		if (dynamic_cast<Menu_button*>(m_game_objects[i]))
		{
			Menu_button* p_Button = dynamic_cast<Menu_button*>(m_game_objects[i]);
			p_Button->set_callback(callbacks[p_Button->get_callback_id()]);
		}
	}
}
