//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2017. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef LEVELSELECTIONSTATE_H
#define LEVELSELECTIONSTATE_H

#include "MenuState.h"
#include "GameObject.h"
#include "StateParser.h"
#include "OptionsState.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class LevelSelectionState : public GameState
{
public:

	LevelSelectionState(std::string);

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_levelSelectionID; };
private:

	void setCallbacks();

	std::string m_currentCategory;

	std::vector<GameObject*> m_gameObjects;

	static const std::string s_levelSelectionID;

	static void s_selectLevel(std::string, std::string);

};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++