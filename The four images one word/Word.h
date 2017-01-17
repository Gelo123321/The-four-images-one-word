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
#include "LetterButton.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Word : public SDLGameObject
{
public:
	void Word::load(const LoaderParams *pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	static void setLetter(std::string letter);
	void setWord(std::string);

	static void setCategory(std::string category) { m_currentCategory = category; }
	static void setLevel(std::string level) { m_currentLevel = level; }

	static void clearWords();

private:

	void createLetters();
	void updateLetters();

	static std::string m_word;
	static std::string m_currentWord;

	static std::string m_currentCategory;
	static std::string m_currentLevel;

	static std::vector<std::string> textureID;

	std::vector<GameObject*> m_gameObjects;
};

class WordCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Word();
	}
};

#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++