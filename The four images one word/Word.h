//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <string>
#include "SDL.h"
#include "SDLGameObject.h"
#include "Game.h"
#include "LoaderParams.h"
#include <vector>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Word : public SDLGameObject
{
public:
	static Word* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Word();
			return s_pInstance;
		}

		return s_pInstance;
	}

	void Word::load(const LoaderParams *pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	void setLetter(std::string letter);
	void setWord(std::string);

	void clearWords();

private:

	Word() {};
	~Word() {};

	static Word* s_pInstance;

	std::string m_word;
	std::string m_currentWord;
};

typedef Word TheWord;

#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++