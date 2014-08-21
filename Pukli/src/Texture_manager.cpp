#include "Texture_manager.h"

Texture_manager* Texture_manager::s_instance = 0;

bool Texture_manager::load(std::string file_name, std::string id, SDL_Renderer* renderer) {
	SDL_Surface* temp_surface = IMG_Load(file_name.c_str());
	if (temp_surface == 0) {
		return false;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
	SDL_FreeSurface(temp_surface);
	if (texture != 0) {
		m_texture_map[id] = texture;
		return true;
	}
	return false;
}

bool Texture_manager::loadText(std::string text, SDL_Color color, TTF_Font* font, std::string id, SDL_Renderer* renderer) {
	SDL_Surface* temp_surface = TTF_RenderText_Solid(font, text.c_str(), color);
	if (temp_surface == 0) {
		return false;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
	SDL_FreeSurface(temp_surface);
	if (texture != 0) {
		m_texture_map[id] = texture;
		return true;
	}
	return false;
}

void Texture_manager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip) {
	SDL_Rect src_rect;
	SDL_Rect dst_rect;

	src_rect.x = 0;
	src_rect.y = 0;
	src_rect.w = dst_rect.w = width;
	src_rect.h = dst_rect.h = height;
	dst_rect.x = x;
	dst_rect.y = y;

	SDL_RenderCopyEx(renderer, m_texture_map[id], &src_rect, &dst_rect, 0, 0, flip);

}

void Texture_manager::draw_frame(std::string id, int x, int y, int width, int height, int current_row, int current_frame, SDL_Renderer* renderer, SDL_RendererFlip flip) {
	SDL_Rect src_rect;
	SDL_Rect dst_rect;

	src_rect.x = width*current_frame;
	src_rect.y = height*current_row;
	src_rect.w = dst_rect.w = width;
	src_rect.h = dst_rect.h = height;
	dst_rect.x = x;
	dst_rect.y = y;

	SDL_RenderCopyEx(renderer, m_texture_map[id], &src_rect, &dst_rect, 0, 0, flip);

}
