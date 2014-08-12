#ifndef __GAME_H__
#define __GAME_H__

#include <vector>
#include <SDL.h>
#include "Game_object.h"
#include "Game_state_machine.h"


class Game {
public:

	static Game* instance() {
		if (s_instance == 0)
			s_instance = new Game();
		return s_instance;
	}

	bool init(const char*, int, int, int, int, bool);
	
	void update();
	void render();
	void handleEvents();
	void clean();
	void quit();

	bool running() const { return m_running; }

	SDL_Renderer* get_renderer() const { return m_renderer; }

private:
	Game() {}
	static Game* s_instance;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	Game_state_machine* m_game_state_machine;

	bool m_running;
};

#define The_Game Game::instance()

#endif