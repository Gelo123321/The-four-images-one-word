//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "LetterButton.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

LetterButton::LetterButton() : SDLGameObject()
{

}

void LetterButton::load(const LoaderParams * pParams)
{
	SDLGameObject::load(pParams);
	m_letter = pParams->getTextureID();
	m_currentFrame = MOUSE_OUT;
}

void LetterButton::draw()
{
	SDLGameObject::draw();
}

void LetterButton::update()
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

			m_callback(m_letter); // call our callback function

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

void LetterButton::clean()
{
	SDLGameObject::clean();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++