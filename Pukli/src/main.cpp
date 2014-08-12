#include "Game.h"

int main(int argc, char** argv) {

	const int FPS = 60;
	const int DELAY_TIME = 1000.0 / FPS;

	Uint32 frame_start, frame_time;

	if (!The_Game->init("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false)) {
		return -1;
	}

	while (The_Game->running()) {

		frame_start = SDL_GetTicks();

		The_Game->handleEvents();
		The_Game->update();
		The_Game->render();

		frame_time = SDL_GetTicks() - frame_start;

		if (frame_time < DELAY_TIME)
			SDL_Delay(round(DELAY_TIME - frame_time));
	}

	The_Game->clean();
	return 0;
}