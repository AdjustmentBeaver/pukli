#include <iostream>
#include "Game.h"
#include "Texture_manager.h"
#include "Input_handler.h"
#include "Player.h"
#include "Enemy.h"
#include "Menu_state.h"
#include "Play_state.h"
#include "utils.h"

#define DEF_RENDER_COLOR_ALPHA 0, 255, 0, 255

Game* Game::s_instance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		LOG << "[SUCC] SDL Init" ;
		m_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_window != 0) {
			LOG << "[SUCC] Window Init" ;
			m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

			if (m_renderer != 0) {
				LOG << "[SUCC] Renderer Init" ;
				SDL_SetRenderDrawColor(m_renderer, DEF_RENDER_COLOR_ALPHA);

				if (!The_Texture_manager->load("assets/BombExploding.png", "bomb", m_renderer))
					return false;


			} else {
				LOG << "[FAIL] Renderer Init" ;
				return false;
			}
		} else {
			LOG << "[FAIL] Windows Init" ;
			return false;
		}
	} else {
		LOG << "[FAIL] SDL Init" ;
		return false;
	}
	LOG << "[SUCC] Game Init" ;
	m_running = true;

	The_Input_handler->init_joysticks();
	m_game_state_machine = new Game_state_machine();
	m_game_state_machine->change_state(new Menu_state());

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
	LOG << "[INFO] Cleanup" ;

	The_Input_handler->clean();

	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}

void Game::handleEvents() {
	The_Input_handler->update();

	if (The_Input_handler->get_joy_button_state(0, 1))
		m_game_state_machine->change_state(new Play_state());
}

void Game::quit() {
	m_running = false;
}
