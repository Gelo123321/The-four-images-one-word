//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "WinState.h"
#include "Game.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
const std::string WinState::s_winID = "WIN";
std::string WinState::m_currentCategory = "";
std::string WinState::m_currentLevel = "";

WinState::WinState(std::string currentCategory, std::string currentLevel)
{
	m_currentCategory = currentCategory;
	m_currentLevel = currentLevel;
}

void WinState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void WinState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool WinState::onEnter()
{
	// parse the state
	StateParser stateParser;
	stateParser.parseState("states.xml", s_winID, &m_gameObjects, &m_textureIDList);
	std::string path = "resources\\category\\" + m_currentCategory + ".xml";
	stateParser.setAttribute(path.c_str(), "LEVELSELECTION", m_currentLevel.c_str());

	m_callbacks.push_back(0);
	m_callbacks.push_back(s_winToMain);
	m_callbacks.push_back(s_nextLevel);

	// set the callbacks for menu items
	setCallbacks(m_callbacks);

	int i = ThePlayer::Instance()->getProgress("none") + 1;
	ThePlayer::Instance()->setProgress("none", i);

	std::cout << "entering WinState\n";  return true;
}

bool WinState::onExit()
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

	std::cout << "exiting WinState\n";
	return true;
}

void WinState::setCallbacks(const std::vector<Callback>& callbacks)
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

void WinState::s_winToMain()
{
	TheGame::Instance()->getStateManager()->changeState(new MainMenuState());
}

void WinState::s_nextLevel()
{
	string level = "";
	for (int i = 0; i < m_currentLevel.length(); i++)
	{
		if (isdigit(m_currentLevel[i]))
		{
			level += m_currentLevel[i];
		}
	}

	m_currentLevel = to_string(stoi(level) + 1);
	TheGame::Instance()->getStateManager()->changeState(new PlayState(m_currentCategory, m_currentLevel));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++