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
#include "WinState.h"
#include "LetterButton.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class PlayState : public GameState
{
public:
	PlayState(std::string, std::string);

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_playID; };
private:

	void setCallbacks();

	std::string m_currentLevel;
	std::string m_currentCategory;

	std::vector<GameObject*> m_gameObjects;

	static const std::string s_playID;

	static void s_setLetter(std::string);
};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++