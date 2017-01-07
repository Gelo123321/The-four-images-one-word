//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "SDL.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "GameObjectFactory.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Player : public SDLGameObject
{
public:
	Player();

	void load(const LoaderParams *pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	void handleInput();
};

// for the factory
class PlayerCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Player();
	}
};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++