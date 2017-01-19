//#############################################################################
// ScrollBar.h - 18/01/2017 (Gelo123321) ######################################
//#############################################################################
#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include <iostream>
#include "SDL.h"
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "GameObjectFactory.h"
#include <vector>
//#############################################################################
class ScrollBar : public SDLGameObject
{
public:
	ScrollBar();

	void load(const LoaderParams* pParams);

	void draw();
	void update();
	void clean();

	void setCallback(void(*callback)(int)) { m_callback = callback; }
	int getCallbackID() { return m_callbackID; }

	void setValue(int value);
private:
	void setValue(Vector2D* pMousePos);

	int m_value;
	int const MIN_VALUE = 0;
	int const MAX_VALUE = 8;

	int m_callbackID;

	void(*m_callback) (int);

	bool m_bReleased;
};

class ScrollBarCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new ScrollBar();
	}
};
#endif
//#############################################################################