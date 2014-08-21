#include <SDL_ttf.h>
#include "debug_window.h"
#include "Game.h"

template<class T> void Debug_watcher<T>::add(const std::string name, const T* value) {
	watched_element tmp = { name, value };
	watched_elements.push_back(tmp);
}

template<class T> void Debug_watcher<T>::render() {
}