//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include <iostream>
#include <vector>
#include "SDL.h"
#include "GameState.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "AnimatedGraphic.h"
#include "MenuState.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class GameOverState : public MenuState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_gameOverID; }
private:

	virtual void setCallbacks(const std::vector<Callback>& callbacks);

	std::vector<GameObject*> m_gameObjects;

	static void s_gameOverToMain();
	static void s_restartPlay();

	static const std::string s_gameOverID;
};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++