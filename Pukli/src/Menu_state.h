#ifndef __MENU_STATE_H__
#define __MENU_STATE_H__

#include <vector>
#include "Game_state.h"

class Menu_state : public Game_state
{
protected:
	typedef void(*Callback)();
	virtual void set_callbacks(const std::vector<Callback>& callbacks) = 0;
	std::vector<Callback> m_callbacks;
};

#endif