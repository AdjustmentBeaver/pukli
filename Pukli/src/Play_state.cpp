#include "Play_state.h"
#include "utils.h"

const std::string Play_state::s_play_id = "PLAY";

void Play_state::update() {}
void Play_state::render() {}

bool Play_state::onEnter() {
	LOG << "entering Play_state";
	return true;
}
bool Play_state::onExit() {
	LOG << "exiting Play_state";
	return true;
}