#include "Debug_window.h"
#include "Game.h"
#include "Texture_manager.h"
#include <string>
#include <sstream>

Debug_watcher* Debug_watcher::s_instance = 0;

void Debug_watcher::draw(int x, int y) {
	// Draw background
	The_Texture_manager->draw(m_background_id, x, y, m_bkg_width + 2 * m_padding, m_bkg_height + 2 * m_padding, The_Game->get_renderer());

	// Draw the watches
	for (std::vector<I_Watch*>::size_type i = 0; i < m_watches.size(); i++) {
		std::string curr_id = m_watch_prefix + m_watches[i]->get_name();
		The_Texture_manager->draw_text(curr_id, x + m_padding, y + m_padding + ((m_bkg_height/m_watches.size()) * i), The_Game->get_renderer());
	}
}

void Debug_watcher::update() {
	int w=1, h=1;
	m_bkg_width = 1;
	for (std::vector<I_Watch*>::size_type i = 0; i < m_watches.size(); i++) {
		std::string curr_id = m_watch_prefix + m_watches[i]->get_name();
		The_Texture_manager->clear_from_texture_map(curr_id);
		The_Texture_manager->load_text(m_watches[i]->get_string().c_str(), m_text_color, The_Game->get_font(), curr_id, The_Game->get_renderer());
		The_Texture_manager->query_texture(curr_id, &w, &h);
		m_bkg_width = (w > m_bkg_width ? w : m_bkg_width);
	}
	m_bkg_height = h * m_watches.size();
}