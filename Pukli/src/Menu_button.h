#ifndef __MENU_BUTTON_H__
#define __MENU_BUTTON_H__

#include "SDL_Game_object.h"

class Menu_button : public SDL_Game_object {
public:
	Menu_button(const Loader_params* params, void (*callback)());

	void draw();
	void update();
	void clean();

	~Menu_button() {}
private:
	static const enum BUTTON_STATE {
		MOUSE_OUT,
		MOUSE_OVER,
		CLICKED,
	};

	void(*m_callback)();
	bool m_released;
};



#endif // !__MENU_BUTTON_H__
