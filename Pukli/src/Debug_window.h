#ifndef __DEBUG_WINDOW_H__
#define __DEBUG_WINDOW_H__

#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "SDL_Game_object.h"
#include "Texture_manager.h"
#include "Game.h"

class Debug_watcher {
public:
	// Singleton
	static Debug_watcher* instance() {
		if (s_instance == 0)
			s_instance = new Debug_watcher();
		return s_instance;
	}
	~Debug_watcher() {
		for (std::vector<I_Watch*>::size_type i = 0; i < m_watches.size(); i++) {
			delete m_watches[i];
		}
		The_Texture_manager->clear_from_texture_map(m_background_id);
	}

	// Functionality
	template <class T> void add(std::string name, const T& value) {
		int tmp_width, tmp_height;
		Watch<T>* watch = new Watch<T>(name, value);
		The_Texture_manager->load_text(watch->get_name(), m_text_color, The_Game->get_font(), m_watch_prefix + name, The_Game->get_renderer());
		The_Texture_manager->query_texture(m_watch_prefix + name, &tmp_width, &tmp_height);
		m_watches.push_back(watch);

	}
	void remove(const std::string name) {
		auto itr = std::find_if(m_watches.begin(), m_watches.end(), [&](const I_Watch* a) {if (a->get_name() == name) return true; return false; });
		if (itr != m_watches.end()) {
			delete *itr;
			m_watches.erase(itr);
		}
	}
	void draw(int x, int y);
	void update();
private:
	// Singleton
	Debug_watcher() : m_text_color(SDL_Color{ 255, 255, 255, 255 }), m_bkg_color(SDL_Color{ 0, 0, 0, 100 }), m_bkg_width(1), m_bkg_height(1) {
		The_Texture_manager->load_rect(m_bkg_width, m_bkg_height, m_bkg_color, m_background_id, The_Game->get_renderer());
	}
	static Debug_watcher* s_instance;
	Debug_watcher(const Debug_watcher&);
	void operator= (const Debug_watcher&);

	// Data
	struct I_Watch {
		virtual std::string get_string() const = 0;
		virtual std::string get_name() const = 0;
		virtual ~I_Watch() {}
	};

	template <class T>
	class Watch : public I_Watch {
	public:
		Watch(std::string name, const T& data) : m_name(name), m_data(data) {}
		~Watch() {}
		// Interface
		std::string get_string() const {
			std::stringstream ss;
			ss << m_name << " : " << m_data;
			return ss.str();
		}
		std::string get_name() const { return m_name; }
	private:
		std::string m_name;
		const T& m_data;
	};

	std::vector<I_Watch*> m_watches;
	const std::string m_background_id = "_watcher_background";
	const std::string m_watch_prefix = "_watch_";
	// Rendering
	const int m_padding = 10;
	int m_bkg_width, m_bkg_height;
	SDL_Color m_text_color;
	SDL_Color m_bkg_color;

};

#define The_Debug_Watcher Debug_watcher::instance()

#endif // !__DEBUG_WINDOW_H__
