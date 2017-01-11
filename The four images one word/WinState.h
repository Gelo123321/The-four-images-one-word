//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef WINSTATE_H
#define WINSTATE_H

#include <iostream>
#include <vector>
#include "SDL.h"
#include "GameState.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "AnimatedGraphic.h"
#include "MenuState.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class WinState : public MenuState
{
public:
	WinState(std::string, std::string);

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_winID; }
private:
	static std::string m_currentLevel;
	static std::string m_currentCategory;

	virtual void setCallbacks(const std::vector<Callback>& callbacks);

	std::vector<GameObject*> m_gameObjects;

	static void s_winToMain();
	static void s_nextLevel();

	static const std::string s_winID;
};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++