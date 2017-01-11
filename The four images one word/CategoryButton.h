//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef CATEGORYBUTTON_H
#define CATEGORYBUTTON_H

#include <iostream>
#include <string>
#include "SDL.h"
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "GameObjectFactory.h"
#include "Word.h"
#include <vector>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class CategoryButton : public SDLGameObject
{
public:
	CategoryButton();

	void CategoryButton::load(const LoaderParams *pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	void setCallback(void(*callback)(std::string)) { m_callback = callback; }
	int getCallbackID() { return m_callbackID; }
private:
	bool isLock;

	int m_callbackID;

	std::string m_currentCategory;

	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	bool m_bReleased;

	void(*m_callback) (std::string);
};

// for the factory
class CategoryButtonCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new CategoryButton();
	}
};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++