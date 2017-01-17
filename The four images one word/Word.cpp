//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Word.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
std::string Word::m_currentWord = "";
std::string Word::m_word = "-1";
std::string Word::m_currentCategory = "";
std::string Word::m_currentLevel = "";
std::vector<std::string> Word::textureID;

void Word::load(const LoaderParams * pParams)
{
	SDLGameObject::load(pParams);
	m_word = pParams->getWord();

	createLetters();
}

void Word::draw()
{
	SDLGameObject::draw();
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

void Word::update()
{
	updateLetters();
	if (m_currentWord.length() == m_word.length())
	{
		if (strcmp(m_currentWord.c_str(), m_word.c_str()) == 0)
		{
			TheGame::Instance()->getStateManager()->changeState(new WinState(m_currentCategory, m_currentLevel));
		}
		else
		{
			/*for (int i = 0; i < m_word.length(); i++)
			{
				m_currentWord[i] = '0';
			}*/
			for (int i = 0; i < m_currentWord.length() / 2; i++)
			{
				dynamic_cast<LetterButton*>(m_gameObjects[i])->setTextureID("img0");
			}
			m_currentWord = "";
			textureID.clear();
		}
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void Word::clean()
{
	SDLGameObject::clean();
}

void Word::setLetter(std::string letter)
{
	//for (int i = 0; i < m_currentWord.length(); i++)
	//{
	//	if (m_currentWord[i] == '0')
	//	{
	//		m_currentWord[i] = letter[0];
	//		return;
	//	}
	//}
	m_currentWord += letter;
	textureID.push_back(letter);
}

void Word::setWord(std::string word)
{
	m_word = word;
}

void Word::clearWords()
{
	m_currentWord = "";
	m_word = "-1";
	textureID.clear();
}

void Word::createLetters()
{
	int posX, posY;

	const int K = 16;

	posX = (480 / 2) - (m_word.length() / 4) * 32;

	if ((m_word.length() / 2) % 2 != 0)
	{
		posX = posX - K;
	}

	posY = 100;

	for (int i = 0; i < m_word.length() / 2; i++)
	{
		GameObject* pGameObject = TheGameObjectFactory::Instance()->create("LetterButton");
		pGameObject->load(new LoaderParams(posX + (i * 32), posY, 32, 32, "img0", 0, i + 1, 0, "", "", "", ""));

		m_gameObjects.push_back(pGameObject);
		//m_currentWord += '0';
	}
}

void Word::updateLetters()
{
	for (int i = 0; i < m_currentWord.length() / 2; i++)
	{
		if (m_currentWord[i] != '0')
		{
			dynamic_cast<LetterButton*>(m_gameObjects[i])->setTextureID(textureID.at(i));
		}
	}
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++