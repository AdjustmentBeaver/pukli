#ifndef __TEXTURE_MANAGER_H__
#define __TEXTURE_MANAGER_H__

#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "utils.h"

class Texture_manager {
public:
	// Singleton
	static Texture_manager* instance() {
		if (s_instance == 0)
			s_instance = new Texture_manager();
		return s_instance;
	}

	// Caching
	bool load(std::string file_name, std::string id, SDL_Renderer* renderer);
	bool load_text(std::string text, SDL_Color color, TTF_Font* font, std::string id, SDL_Renderer* renderer);
	void clear_from_texture_map(std::string id) {
		SDL_DestroyTexture(m_texture_map[id]);
		m_texture_map.erase(id);
	}
	bool load_rect(int w, int h, SDL_Color color, std::string id, SDL_Renderer* renderer);

	// Rendering
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void draw_frame(std::string id, int x, int y, int width, int height, int current_row, int current_frame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void draw_text(std::string id, int x, int y, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// Query
	int query_texture(const std::string texture, int* w, int* h) { return SDL_QueryTexture(m_texture_map[texture], 0,0,w,h); }
private:
	// Singleton
	Texture_manager() {}
	static Texture_manager* s_instance;

	// Data
	std::map<std::string, SDL_Texture*> m_texture_map;
};

#define The_Texture_manager Texture_manager::instance()

#endif