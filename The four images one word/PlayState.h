//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include <iostream>
#include <vector>
#include "SDL.h"
#include "GameState.h"
#include "StateParser.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "GameObject.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);

	virtual std::string getStateID() const { return s_playID; };
private:

	std::vector<GameObject*> m_gameObjects;

	static const std::string s_playID;
};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++