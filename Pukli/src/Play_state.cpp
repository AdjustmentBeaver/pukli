#include "Play_state.h"
#include "utils.h"

const std::string Play_state::s_play_id = "PLAY";

void Play_state::update() {}
void Play_state::render() {}

bool Play_state::on_enter() {
	LOG << "entering Play_state";
	return true;
}
bool Play_state::on_exit() {
	LOG << "exiting Play_state";
	return true;
}