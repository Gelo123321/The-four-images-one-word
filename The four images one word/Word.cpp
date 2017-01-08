//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Word.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Word* Word::s_pInstance = 0;

void Word::load(const LoaderParams * pParams)
{
	SDLGameObject::load(pParams);
	m_word = pParams->getWord();
}

void Word::draw()
{
	SDLGameObject::draw();
}

void Word::update()
{
	if (m_currentWord.length() == m_word.length() &&
		strcmp(m_currentWord.c_str(), m_word.c_str()) == 0)
	{
		TheGame::Instance()->getStateManager()->changeState(new WinState());
	}
}

void Word::clean()
{
	SDLGameObject::clean();
}

void Word::setLetter(std::string letter)
{
	m_currentWord += letter;
}

void Word::setWord(std::string word)
{
	m_word = word;
}

void Word::clearWords()
{
	m_currentWord = "";
	m_word = "-1";
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++