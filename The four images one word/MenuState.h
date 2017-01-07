//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <iostream>
#include <vector>
#include "SDL.h"
#include "GameState.h"
#include "TextureManager.h"
#include "MenuButton.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class MenuState : public GameState
{
public:

	virtual ~MenuState() {}

protected:

	typedef void(*Callback)();
	virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;

	std::vector<Callback> m_callbacks;
};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++