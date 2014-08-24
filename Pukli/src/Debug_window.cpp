#include "Debug_window.h"
#include "Game.h"
#include "Texture_manager.h"
#include <string>
#include <sstream>

Debug_watcher* Debug_watcher::s_instance = 0;

void Debug_watcher::draw(int x, int y) {

	// Draw background

	// Draw the watches
	for (std::vector<I_Watch*>::size_type i = 0; i < m_watches.size(); i++) {
		std::string curr_id = "watch" + std::to_string(i);
		The_Texture_manager->clear_from_texture_map(curr_id);
		The_Texture_manager->load_text(m_watches[i]->get_string().c_str(), SDL_Color{ 0, 0, 0, 255 }, The_Game->get_font(), curr_id, The_Game->get_renderer());
		The_Texture_manager->draw_text(curr_id, x, y+(15*i), The_Game->get_renderer());
	}
}
