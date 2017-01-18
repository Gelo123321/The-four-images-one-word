//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2017. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "LevelSelectionState.h"
#include "Game.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
const std::string LevelSelectionState::s_levelSelectionID = "LEVELSELECTION";
std::string LevelSelectionState::m_currentCategory = "";

LevelSelectionState::LevelSelectionState(std::string currentCategory)
{
	m_currentCategory = currentCategory;
}

void LevelSelectionState::update()
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

void LevelSelectionState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool LevelSelectionState::onEnter()
{
	StateParser stateParser;
	std::string path = "resources\\category\\" + m_currentCategory + ".xml";
	stateParser.parseState(path.c_str(), s_levelSelectionID, &m_gameObjects, &m_textureIDList);

	setCallbacks();

	std::cout << "entering LevelSelectionState\n";
	return true;
}

bool LevelSelectionState::onExit()
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

	std::cout << "exiting LevelSelectionState\n";
	return true;
}

void LevelSelectionState::setCallbacks()
{
	// go through the game objects
	if (!m_gameObjects.empty())
	{
		for (int i = 0; i < m_gameObjects.size(); i++)
		{
			// if they are of type MenuButton then assign a callback based on the id passed in from the file
			if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
			{
				MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
				pButton->setCallback(s_selectLevel);
			}
		}
	}
}

void LevelSelectionState::s_selectLevel(int currentLevel)
{
	TheGame::Instance()->getStateManager()->changeState(new PlayState(m_currentCategory, "lvl" + to_string(currentLevel)));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++