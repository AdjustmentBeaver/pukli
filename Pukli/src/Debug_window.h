#ifndef __DEBUG_WINDOW_H__
#define __DEBUG_WINDOW_H__

#include <sstream>
#include <string>
#include <vector>

template<class T> class Debug_watcher {
public:
	void add(const std::string name, const T* value);

	void render();

	static Debug_watcher& instance() {
		static Debug_watcher instance;
		return instance;
	}

	~Debug_watcher() {

	}

private:
	struct watched_element
	{
		std::string name;
		T* data;
	};

	std::vector <watched_element> watched_elements;

	Debug_watcher() {
	}

	Debug_watcher(const Debug_watcher&);

	void operator = (const Debug_watcher&);
};

#define The_Debug_Watcher Debug_watcher::instance()

#endif // !__DEBUG_WINDOW_H__
