#include <algorithm>
#include "Game_state_machine.h"
#include "utils.h"


void Game_state_machine::push_state(Game_state* state) {
	m_states.push_back(state);
	m_states.back()->on_enter();
	LOG << "PSH states:"; std::for_each(m_states.begin(), m_states.end(), [](Game_state* gs) {LOG << gs->get_state_id(); });
}
void Game_state_machine::pop_state() {
	if (!m_states.empty()) {
		if (m_states.back()->on_exit()) {
			////delete m_states.back();
			m_states.pop_back();
		}
	}
	LOG << "POP states:"; std::for_each(m_states.begin(), m_states.end(), [](Game_state* gs) {LOG << gs->get_state_id(); });
}
void Game_state_machine::change_state(Game_state* state) {
	if (!m_states.empty()) {
		if (m_states.back()->get_state_id() == state->get_state_id())
			return;
		pop_state();
	}
	push_state(state);
	LOG << "CHG states:"; std::for_each(m_states.begin(), m_states.end(), [](Game_state* gs) {LOG << gs->get_state_id(); });
}

void Game_state_machine::update() {
	if (!m_states.empty())
		m_states.back()->update();
}
void Game_state_machine::render() {
	if (!m_states.empty())
		m_states.back()->render();
}

const Game_state* Game_state_machine::get_current_state() const {
	if (!m_states.empty())
		return m_states.back();
	return 0;
}
