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
	m_callbacks.push_back(s_optionsToMain);
	m_callbacks.push_back(s_setVolumeSFX);
	m_callbacks.push_back(s_setVolumeMusic);
	m_callbacks.push_back(s_empty);

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
			else if (dynamic_cast<ScrollBar*>(m_gameObjects[i]))
			{
				ScrollBar* pButton = dynamic_cast<ScrollBar*>(m_gameObjects[i]);
				pButton->setCallback(callbacks[pButton->getCallbackID()]);
				if (pButton->getCallbackID() == 2)
				{
					int SFX_volume = TheSoundManager::Instance()->getVolumeSFX();
					pButton->setValue(SFX_volume / 4);
				}
				else if (pButton->getCallbackID() == 3)
				{
					int music_volume = TheSoundManager::Instance()->getVolumeMusic();
					pButton->setValue(music_volume / 4);
				}
			}
		}
	}
}

void OptionsState::s_optionsToMain(int callbackID)
{
	TheGame::Instance()->getStateManager()->changeState(new MainMenuState());
}

void OptionsState::s_setVolumeSFX(int volume)
{
	TheSoundManager::Instance()->setVolumeSFX(volume * 4);
	TheConfigManager::Instance()->set("SFX_volume", volume * 4);
}

void OptionsState::s_setVolumeMusic(int volume)
{
	TheSoundManager::Instance()->setVolumeMusic(volume * 4);
	TheConfigManager::Instance()->set("music_volume", volume * 4);
}

void OptionsState::s_empty(int callbackID)
{
	//
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++