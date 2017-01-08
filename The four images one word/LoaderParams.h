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

	LoaderParams(int x, int y, int width, int height, std::string textureID, int numFrames, int callbackID = 0 , int animSpeed = 0, std::string word = "") :
		m_x(x),
		m_y(y),
		m_width(width),
		m_height(height),
		m_textureID(textureID),
		m_numFrames(numFrames),
		m_callbackID(callbackID),
		m_animSpeed(animSpeed),
		m_word(word)
	{

	}

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	std::string getTextureID() const { return m_textureID; }
	int getNumFrames() const { return m_numFrames; }
	int getCallbackID() const { return m_callbackID; }
	int getAnimSpeed() const { return m_animSpeed; }
	std::string getWord() const { return m_word; }

private:

	int m_x;
	int m_y;

	int m_width;
	int m_height;

	int m_callbackID;
	int m_animSpeed;

	std::string m_textureID;

	int m_numFrames;

	std::string m_word;
};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++