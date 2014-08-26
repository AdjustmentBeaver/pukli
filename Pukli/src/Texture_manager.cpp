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

bool Texture_manager::load_text(std::string text, SDL_Color color, TTF_Font* font, std::string id, SDL_Renderer* renderer) {
	SDL_Surface* temp_surface = TTF_RenderText_Solid(font, text.c_str(), color);
	if (temp_surface == 0) {
		return false;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
	SDL_FreeSurface(temp_surface);
	if (texture != 0) {
		SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
		SDL_SetTextureAlphaMod(texture, color.a);
		m_texture_map[id] = texture;
		return true;
	}
	return false;
}

bool Texture_manager::load_rect(int w, int h, SDL_Color color, std::string id, SDL_Renderer* renderer) {
	SDL_Surface* s = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	SDL_FillRect(s, 0, SDL_MapRGB(s->format, color.r, color.g, color.b));
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, s);
	SDL_FreeSurface(s);
	if (texture != 0) {
		SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
		SDL_SetTextureAlphaMod(texture, color.a);
		m_texture_map[id] = texture;
		return true;
	}
	return false;
}

void Texture_manager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip) {
	draw_frame(id, x, y, width, height, 0, 0, renderer, flip);
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

void Texture_manager::draw_text(std::string id, int x, int y, SDL_Renderer* renderer, SDL_RendererFlip flip) {
	int w, h;
	SDL_QueryTexture(m_texture_map[id], 0, 0, &w, &h);
	draw(id, x, y, w, h, renderer, flip);
}
