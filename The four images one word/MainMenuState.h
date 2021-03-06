//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "MenuState.h"
#include "GameObject.h"
#include "StateParser.h"
#include "OptionsState.h"
#include "CategorySelectionState.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class MainMenuState : public MenuState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; };
private:

	virtual void setCallbacks(const std::vector<Callback> & callbacks);

	std::vector<GameObject*> m_gameObjects;

	static void s_menuToPlay(int);
	static void s_options(int);
	static void s_exitFromMenu(int);

	static const std::string s_menuID;

	std::vector<Callback> m_callbacks;
};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++