#ifndef __GAME_H__
#define __GAME_H__

#include <vector>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Game_object.h"
#include "Game_state_machine.h"

class Game {
public:
	// Singleton
	static Game* instance() {
		if (s_instance == 0)
			s_instance = new Game();
		return s_instance;
	}

	// Init - window parameters
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	// Game loop functions
	void update();
	void render();
	void handleEvents();
	void clean();
	void quit();
	bool running() const { return m_running; }

	// SDL functions
	SDL_Renderer* get_renderer() const { return m_renderer; }

	TTF_Font* get_font() const { return m_font; }

	//State machine functions
	Game_state_machine* get_state_machine() { return m_game_state_machine; }
private:
	// Singleton
	Game() {}
	static Game* s_instance;

	// SDL data
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	TTF_Font* m_font;

	// State machine
	Game_state_machine* m_game_state_machine;

	// Game loop data
	bool m_running;
};

#define The_Game Game::instance()

#endif