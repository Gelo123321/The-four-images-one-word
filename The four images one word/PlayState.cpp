//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "PlayState.h"
#include "Game.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
const std::string PlayState::s_playID = "PLAY";

PlayState::PlayState(std::string currentCategory, std::string currentLevel)
{
	m_currentLevel = currentLevel;
	m_currentCategory = currentCategory;
}

void PlayState::update()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) 
	{
		TheGame::Instance()->getStateManager()->pushState(new PauseState);
	}

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	if (strcmp(m_currentLevel.c_str(), "lvl2") == 0)
	{
		StateParser levelParser;
	}
	// parse the lavel  
	StateParser levelParser;
	std::string ID = "lvl" + m_currentLevel;
	std::string path = "resources\\category\\" + m_currentCategory + ".xml";
	levelParser.parseState(path.c_str(), ID, &m_gameObjects, &m_textureIDList);

	Word::setCategory(m_currentCategory);
	Word::setLevel(m_currentLevel);

	setCallbacks();

	std::cout << "entering PlayState\n"; 
	return true;
}

bool PlayState::onExit()
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

	Word::clearWords();

	std::cout << "exiting PlayState\n";
	return true;
}

void PlayState::setCallbacks()
{
	// go through the game objects
	if (!m_gameObjects.empty())
	{
		for (int i = 0; i < m_gameObjects.size(); i++)
		{
			// if they are of type MenuButton then assign a callback based on the id passed in from the file
			if (dynamic_cast<LetterButton*>(m_gameObjects[i]))
			{
				LetterButton* pButton = dynamic_cast<LetterButton*>(m_gameObjects[i]);
				pButton->setCallback(s_setLetter);
			}
		}
	}
}

void PlayState::s_setLetter(std::string currentLetter)
{
	Word::setLetter(currentLetter);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++