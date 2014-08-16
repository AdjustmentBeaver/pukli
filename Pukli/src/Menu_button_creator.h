#ifndef __MENU_BUTTON_CREATOR_H__
#define __MENU_BUTTON_CREATOR_H__

#include "Game_object_factory.h"
#include "Game_object.h"
#include "Menu_button.h"

class Menu_button_creator : public Base_creator {
	
	Game_object* createGameObject() const
	{
		return new Menu_button();
	}
};

#endif