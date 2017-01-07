//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <iostream>
#include "SDL.h"
#include "GameState.h"
#include <vector>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class StateManager 
{
public:
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();

	void update();
	void render();
private:
	std::vector<GameState*> m_gameStates;
};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++