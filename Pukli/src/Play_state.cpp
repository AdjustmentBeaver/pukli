#include "Play_state.h"
#include "Menu_button.h"
#include "Pause_state.h"
#include "Player.h"
#include "utils.h"
#include "Texture_manager.h"
#include "Input_handler.h"
#include "Game.h"

const std::string Play_state::s_play_id = "PLAY";

void Play_state::update() {
	if (The_Input_handler->is_key_down(SDL_SCANCODE_ESCAPE))
		The_Game->get_state_machine()->push_state(new Pause_state());

	for (std::vector<Game_object*>::size_type i = 0; i < m_game_objects.size(); i++) {
		m_game_objects[i]->update();
	}
}

void Play_state::render() {
	for (std::vector<Game_object*>::size_type i = 0; i < m_game_objects.size(); i++) {
		m_game_objects[i]->draw();
	}
}

bool Play_state::on_enter() {
	LOG << "entering Play_state";
	if (!The_Texture_manager->load("../assets/default.bmp", "fasz", The_Game->get_renderer())) {
		return false;
	}
	m_game_objects.push_back(new Player(new Loader_params(0,0,640,480,"fasz")));
	return true;
}

bool Play_state::on_exit() {
	LOG << "exiting Play_state";
	for (std::vector<Game_object*>::size_type i = 0; i < m_game_objects.size(); i++) {
		m_game_objects[i]->clean();
	}
	m_game_objects.clear();
	The_Texture_manager->clear_from_texture_map("raccoon");

	return true;
}