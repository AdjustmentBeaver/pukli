#ifndef __MENU_BUTTON_H__
#define __MENU_BUTTON_H__

#include "SDL_Game_object.h"

class Menu_button : public SDL_Game_object {
public:
	Menu_button(const Loader_params* params, void (*callback)());
	Menu_button();

	void load(const Loader_params *pParams);
	void draw();
	void update();
	void clean();

	void set_callback(void(*callback)()) { m_callback = callback; }
	int get_callback_id() { return m_callback_id; }

	~Menu_button() {}
private:
	static const enum BUTTON_STATE {
		MOUSE_OUT,
		MOUSE_OVER,
		CLICKED,
	};

	void(*m_callback)();
	int m_callback_id;
	bool m_released;
};



#endif // !__MENU_BUTTON_H__
