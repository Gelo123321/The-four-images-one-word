//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "GameOverState.h"
#include "Game.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void GameOverState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool GameOverState::onEnter()
{
 
	// parse the state
	StateParser stateParser;
	stateParser.parseState("test.xml", s_gameOverID, &m_gameObjects,   &m_textureIDList);

	m_callbacks.push_back(0);
	m_callbacks.push_back(s_gameOverToMain);
	m_callbacks.push_back(s_restartPlay);

	// set the callbacks for menu items
	setCallbacks(m_callbacks);

	std::cout << "entering PauseState\n";  return true;
}

bool GameOverState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	TheTextureManager::Instance()->clearFromTextureMap("resumebutton");

	std::cout << "exiting GameOverState\n";
	return true;
}

void GameOverState::setCallbacks(const std::vector<Callback>& callbacks)
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

void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateManager()->changeState(new MainMenuState());
}

void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateManager()->changeState(new PlayState());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++