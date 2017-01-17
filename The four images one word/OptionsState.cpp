//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2017. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "OptionsState.h"
#include "Game.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
const std::string OptionsState::s_optionsID = "OPTIONS";

void OptionsState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void OptionsState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool OptionsState::onEnter()
{
	StateParser stateParser;
	stateParser.parseState("states.xml", s_optionsID, &m_gameObjects, &m_textureIDList);

	m_callbacks.push_back(0);
	for (int i = 1; i < 6; i++)
	{
		m_callbacks.push_back(s_setVolumeSFX);
	}
	m_callbacks.push_back(s_optionsToMain);


	setCallbacks(m_callbacks);

	std::cout << "entering OptionsState\n";
	return true;
}

bool OptionsState::onExit()
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

	std::cout << "exiting OptionsState\n";
	return true;
}

void OptionsState::setCallbacks(const std::vector<Callback>& callbacks)
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

void OptionsState::s_optionsToMain(int callbackID)
{
	TheGame::Instance()->getStateManager()->changeState(new MainMenuState());
}

void OptionsState::s_setVolumeSFX(int callbackID)
{
	int volume = 0;
	switch (callbackID)
	{
	case 1:
		volume = 0;
		break;
	case 2:
		volume = 32;
		break;
	case 3:
		volume = 64;
		break;
	case 4:
		volume = 96;
		break;
	case 5:
		volume = 128;
		break;
	}
	
	TheSoundManager::Instance()->setVolumeSFX(volume);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++