//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "PauseState.h"
#include "Game.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PauseState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PauseState::onEnter()
{
	StateParser stateParser;
	stateParser.parseState("test.xml", s_pauseID, &m_gameObjects, &m_textureIDList);

	m_callbacks.push_back(0);
	m_callbacks.push_back(s_pauseToMain);
	m_callbacks.push_back(s_resumePlay);


	setCallbacks(m_callbacks);

	std::cout << "entering PauseState\n";
	return true;
}

bool PauseState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();

	// clear the texture manager
	for(int i = 0; i < m_textureIDList.size(); i++) 
	{
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}

	std::cout << "exiting PauseState\n";
	return true;
}

void PauseState::setCallbacks(const std::vector<Callback>& callbacks)
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

void PauseState::s_pauseToMain()
{
	TheGame::Instance()->getStateManager()->changeState(new MainMenuState());
}

void PauseState::s_resumePlay()
{
	TheGame::Instance()->getStateManager()->popState();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++