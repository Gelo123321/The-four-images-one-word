//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2017. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef LETTERBUTTON_H
#define LETTERBUTTON_H

#include <iostream>
#include <string>
#include "SDL.h"
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "GameObjectFactory.h"
#include"PlayState.h"
#include "Word.h"
#include <vector>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class LetterButton : public SDLGameObject
{
public:
	LetterButton();

	void LetterButton::load(const LoaderParams *pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
	
	void setCallback(void(*callback)(std::string)) { m_callback = callback; }
	int getCallbackID() { return m_callbackID; }

	virtual void setTextureID(std::string textureID) { m_textureID = textureID; }
private:
	std::string m_letter;

	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	int m_callbackID;

	void(*m_callback) (std::string);

	bool m_bReleased;
};

// for the factory
class LetterButtonCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new LetterButton();
	}
};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++