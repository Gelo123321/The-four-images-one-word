//#############################################################################
// ScrollBar.cpp - 18/01/2017 (Gelo123321) ####################################
//#############################################################################
#include "ScrollBar.h"
//#############################################################################

ScrollBar::ScrollBar() : SDLGameObject()
{
	m_value = 0;
}

void ScrollBar::update()
{
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

	if (pMousePos->getX() < (m_position.getX() + m_width)
		&& pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < (m_position.getY() + m_height)
		&& pMousePos->getY() > m_position.getY())
	{
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased)
		{
			setValue(pMousePos);

			m_callback(m_value); // call our callback function

			m_bReleased = false;
		}
		else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_bReleased = true;
		}
	}
}

void ScrollBar::clean()
{
	SDLGameObject::clean();
}

void ScrollBar::load(const LoaderParams * pParams)
{
	SDLGameObject::load(pParams);
	m_callbackID = pParams->getCallbackID();
	m_value = MIN_VALUE;
}

void ScrollBar::draw()
{
	SDLGameObject::draw();
}

void ScrollBar::setValue(int value)
{
	value <= MAX_VALUE ? m_value = value : m_value = MAX_VALUE;
	value >= MIN_VALUE ? m_value = value : m_value = MIN_VALUE;

	m_currentFrame = m_value;

	m_callback(m_value); // call our callback function
}

void ScrollBar::setValue(Vector2D* pMousePos)
{
	int K = m_width / MAX_VALUE;

	for (int i = MIN_VALUE; i <= MAX_VALUE; i++) 
	{
		if (pMousePos->getX() > ((m_position.getX() + m_width) - (K * i)))
		{
			m_value = MAX_VALUE - i;
			m_currentFrame = m_value;
			return;
		}
	}
}

//#############################################################################