//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "MainMenuState.h"
#include "Game.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
const std::string MainMenuState::s_menuID = "MENU";

void MainMenuState::update()
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

void MainMenuState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MainMenuState::onEnter()
{
	StateParser stateParser;
	stateParser.parseState("states.xml", s_menuID, &m_gameObjects, &m_textureIDList);

	m_callbacks.push_back(0);
	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_options);
	m_callbacks.push_back(s_exitFromMenu);

	setCallbacks(m_callbacks);

	std::cout << "entering MainMenuState\n";
	return true;
}

bool MainMenuState::onExit()
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

	std::cout << "exiting MainMenuState\n";
	return true;
}

void MainMenuState::setCallbacks(const std::vector<Callback>& callbacks)
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
				pButton->setCallback(callbacks[pButton->getCallbackID()]);
			}
		}
	}
}

void MainMenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateManager()->changeState(new PlayState());
}

void MainMenuState::s_options()
{
	TheGame::Instance()->getStateManager()->changeState(new OptionsState());
}

void MainMenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++