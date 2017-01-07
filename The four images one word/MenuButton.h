//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <iostream>
#include "SDL.h"
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "GameObjectFactory.h"
#include <vector>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class MenuButton : public SDLGameObject
{
public:

	MenuButton();

	void load(const LoaderParams* pParams);

	void draw();
	void update();
	void clean();

	void setCallback(void(*callback)()) { m_callback = callback; }
	int getCallbackID() { return m_callbackID; }
private:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	int m_callbackID;

	void (*m_callback) ();

	bool m_bReleased;
};

class MenuButtonCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new MenuButton();
	}
};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++