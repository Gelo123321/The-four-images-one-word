//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2017. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "CategorySelectionState.h"
#include "Game.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
const std::string CategorySelectionState::s_categorySelectionID = "CATEGORYSELECTION";

void CategorySelectionState::update()
{
	if (!m_gameObjects.empty())
	{
		for (int i = 0; i < m_gameObjects.size(); i++)
		{
			if (m_gameObjects[i] != 0)
			{
				m_gameObjects[i]->update();
			}
		}
	}
}

void CategorySelectionState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool CategorySelectionState::onEnter()
{
	StateParser stateParser;
	stateParser.parseState("states.xml", s_categorySelectionID, &m_gameObjects, &m_textureIDList);

	setCallbacks();

	std::cout << "entering CategorySelectionState\n";
	return true;
}

bool CategorySelectionState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();

	// clear the texture manager 
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}

	std::cout << "exiting CategorySelectionState\n";
	return true;
}

void CategorySelectionState::setCallbacks()
{
	// go through the game objects
	if (!m_gameObjects.empty())
	{
		for (int i = 0; i < m_gameObjects.size(); i++)
		{
			// if they are of type MenuButton then assign a callback based on the id passed in from the file
			if (dynamic_cast<CategoryButton*>(m_gameObjects[i]))
			{
				CategoryButton* pButton = dynamic_cast<CategoryButton*>(m_gameObjects[i]);
				pButton->setCallback(s_selectCategory);
			}
		}
	}
}

void CategorySelectionState::s_selectCategory(std::string currentCategory)
{
	TheGame::Instance()->getStateManager()->changeState(new LevelSelectionState(currentCategory));
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++