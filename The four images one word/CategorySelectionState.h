//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2017. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef CATEGORYSELECTIONSTATE_H
#define CATEGORYSELECTIONSTATE_H

#include "MenuState.h"
#include "GameObject.h"
#include "StateParser.h"
#include "OptionsState.h"
#include "LevelSelectionState.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class CategorySelectionState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_categorySelectionID; };
private:

	virtual void setCallbacks();

	std::vector<GameObject*> m_gameObjects;

	static void s_selectCategory(std::string);

	static const std::string s_categorySelectionID;

};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++