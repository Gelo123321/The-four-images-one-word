//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef LEVELBUTTON_H
#define LEVELBUTTON_H

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
class LevelButton : public SDLGameObject
{
public:
	LevelButton();

	void LevelButton::load(const LoaderParams *pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	void setCallback(void(*callback)(std::string, std::string)) { m_callback = callback; }
	int getCallbackID() { return m_callbackID; }
private:
	bool isLock;

	int m_callbackID;

	std::string m_currentCategory;
	std::string m_currentLevel;

	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	bool m_bReleased;

	void(*m_callback) (std::string, std::string);
};

// for the factory
class LevelButtonCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new LevelButton();
	}
};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++