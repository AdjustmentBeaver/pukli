#ifndef __DEBUG_WINDOW_H__
#define __DEBUG_WINDOW_H__

#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "SDL_Game_object.h"

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
	}

	// Functionality
	template <class T> void add(const std::string name, const T& value) {
		m_watches.push_back(new Watch<T>(name, value));
	}
	void remove(const std::string name) {
		auto itr = std::find_if(m_watches.begin(), m_watches.end(), [&](const I_Watch* a) {if (a->get_name() == name) return true; return false; });
		if (itr != m_watches.end()) {
			delete *itr;
			m_watches.erase(itr);
		}
	}
	void draw(int x, int y);
private:
	// Singleton
	static Debug_watcher* s_instance;
	Debug_watcher() {}
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

	// Rendering
	static const int padding = 10;
};

#define The_Debug_Watcher Debug_watcher::instance()

#endif // !__DEBUG_WINDOW_H__
