//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef LETTER_H
#define LETTER_H

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
class Letter : public SDLGameObject
{
public:
	Letter();

	void Letter::load(const LoaderParams *pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
	
private:
	std::string m_letter;

	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	bool m_bReleased;
};

// for the factory
class LetterCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Letter();
	}
};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++