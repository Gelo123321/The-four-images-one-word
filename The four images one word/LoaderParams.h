//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H

#include <iostream>
#include "SDL.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class LoaderParams
{
public:

	LoaderParams(int x, int y, int width, int height, std::string textureID, int numFrames, int callbackID = 0, int animSpeed = 0, std::string category = "", std::string level = "", std::string letter = "", std::string word = "") :
		m_x(x),
		m_y(y),
		m_width(width),
		m_height(height),
		m_textureID(textureID),
		m_numFrames(numFrames),
		m_callbackID(callbackID),
		m_animSpeed(animSpeed),
		m_category(category),
		m_level(level),
		m_letter(letter),
		m_word(word)
	{

	}

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	std::string getTextureID() const { return m_textureID; }
	std::string getCategory() const { return m_category; }
	std::string getLevel() const { return m_level; }
	std::string getLetter() const { return m_letter; }
	std::string getWord() const { return m_word; }
	int getNumFrames() const { return m_numFrames; }
	int getCallbackID() const { return m_callbackID; }
	int getAnimSpeed() const { return m_animSpeed; }

protected:

	int m_x;
	int m_y;

	int m_width;
	int m_height;

	int m_callbackID;
	int m_animSpeed;

	std::string m_textureID;
	std::string m_category;
	std::string m_level;
	std::string m_letter;
	std::string m_word;

	int m_numFrames;
};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++