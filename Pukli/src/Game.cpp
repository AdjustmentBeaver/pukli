#include <iostream>
#include "Game.h"
#include "Game_object_factory.h"
#include "Menu_button_creator.h"
#include "Player_creator.h"
#include "Enemy_creator.h"
#include "Texture_manager.h"
#include "Input_handler.h"
#include "Player.h"
#include "Enemy.h"
#include "Main_menu_state.h"
#include "Play_state.h"
#include "utils.h"

#define DEF_RENDER_COLOR_ALPHA 255, 255, 255, 255

Game* Game::s_instance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		LOG << "[SUCC] SDL Init";
		m_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_window != 0) {
			LOG << "[SUCC] Window Init";
			m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

			if (m_renderer != 0) {
				LOG << "[SUCC] Renderer Init";
				SDL_SetRenderDrawColor(m_renderer, DEF_RENDER_COLOR_ALPHA);

				if (TTF_Init() != -1){
					LOG << "[SUCC] TTF Init";
					m_font = TTF_OpenFont("../assets/leves.ttf", 10);
					if (m_font != NULL) {
						LOG << "[SUCC] TTF Load";
					}
					else {
						LOG << "[FAIL] TTF Load";
						return false;
					}
				}
				else {
					LOG << "[FAIL] TTF Init";
					return false;
				}
			} else {
				LOG << "[FAIL] Renderer Init";
				return false;
			}
		} else {
			LOG << "[FAIL] Windows Init";
			return false;
		}
	} else {
		LOG << "[FAIL] SDL Init";
		return false;
	}
	LOG << "[SUCC] Game Init";
	m_running = true;

	//Register types
	The_Game_object_factory->register_type("Menu_button", new Menu_button_creator());
	The_Game_object_factory->register_type("Player", new Player_creator());
	The_Game_object_factory->register_type("Enemy", new Enemy_creator());

	The_Input_handler->init_joysticks();
	m_game_state_machine = new Game_state_machine();
	m_game_state_machine->change_state(new Main_menu_state());

	return true;
}

void Game::update() {
	m_game_state_machine->update();
}

void Game::render() {
	SDL_RenderClear(m_renderer);

	m_game_state_machine->render();

	SDL_RenderPresent(m_renderer);
}

void Game::clean() {
	LOG << "[INFO] Cleanup";

	The_Input_handler->clean();

	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}

void Game::handleEvents() {
	The_Input_handler->update();
}

void Game::quit() {
	m_running = false;
}