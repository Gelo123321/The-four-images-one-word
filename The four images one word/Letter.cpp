//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Letter.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Letter::Letter() : SDLGameObject()
{

}

void Letter::load(const LoaderParams * pParams)
{
	SDLGameObject::load(pParams);
	m_letter = pParams->getTextureID();
	m_currentFrame = MOUSE_OUT;
}

void Letter::draw()
{
	SDLGameObject::draw();
}

void Letter::update()
{
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

	if (pMousePos->getX() < (m_position.getX() + m_width)
		&& pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < (m_position.getY() + m_height)
		&& pMousePos->getY() > m_position.getY())
	{
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased)
		{
			m_currentFrame = CLICKED;

			TheWord::Instance()->setLetter(m_letter); // call our callback function

			m_bReleased = false;
		}
		else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_bReleased = true;
			m_currentFrame = MOUSE_OVER;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}

void Letter::clean()
{
	SDLGameObject::clean();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++