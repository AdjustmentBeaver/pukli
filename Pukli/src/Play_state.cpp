#include "Play_state.h"
#include "Menu_button.h"
#include "Pause_state.h"
#include "Player.h"
#include "Enemy.h"
#include "utils.h"
#include "Texture_manager.h"
#include "Input_handler.h"
#include "Game.h"
#include "Game_over_state.h"
#include "State_parser.h"

const std::string Play_state::s_play_id = "PLAY";

void Play_state::update() {
	if (The_Input_handler->is_key_down(SDL_SCANCODE_ESCAPE))
		The_Game->get_state_machine()->push_state(new Pause_state());

	for (std::vector<Game_object*>::size_type i = 0; The_Game->get_state_machine()->get_current_state() == this && i < m_game_objects.size(); i++) {
		m_game_objects[i]->update();
	}

	if (checkCollision(dynamic_cast<SDL_Game_object*> (m_game_objects[0]), dynamic_cast<SDL_Game_object*> (m_game_objects[1]))) {
		The_Game->get_state_machine()->push_state(new Game_over_state());
	}
}

void Play_state::render() {
	for (std::vector<Game_object*>::size_type i = 0; The_Game->get_state_machine()->get_current_state() == this && i < m_game_objects.size(); i++) {
		m_game_objects[i]->draw();
	}
}

bool Play_state::on_enter() {
	LOG << "entering Play_state";

	State_parser state_parser;
	state_parser.parse_state("../config/states.json", s_play_id, &m_game_objects, &m_texture_ids);

	return true;
}

bool Play_state::on_exit() {
	LOG << "exiting Play_state";

	for (std::vector<std::string>::size_type i = 0; i < m_texture_ids.size(); i++) {
		The_Texture_manager->clear_from_texture_map(m_texture_ids[i]);
	}
	for (std::vector<Game_object*>::size_type i = 0; i < m_game_objects.size(); i++) {
		m_game_objects[i]->clean();
		//delete m_game_objects[i];
	}
	m_game_objects.clear();

	return true;
}

bool Play_state::checkCollision(SDL_Game_object* p1, SDL_Game_object* p2) {
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	leftA = p1->get_position().get_x();
	rightA = p1->get_position().get_x() + p1->get_width();
	topA = p1->get_position().get_y();
	bottomA = p1->get_position().get_y() + p1->get_height();
	//Calculate the sides of rect B 
	leftB = p2->get_position().get_x();
	rightB = p2->get_position().get_x() + p2->get_width();
	topB = p2->get_position().get_y();
	bottomB = p2->get_position().get_y() + p2->get_height();
	//If any of the sides from A are outside of B  
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}

Play_state::~Play_state() {}