//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "LevelButton.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

LevelButton::LevelButton() : SDLGameObject()
{
	isLock = false;
}

void LevelButton::load(const LoaderParams * pParams)
{
	SDLGameObject::load(pParams);
	m_callbackID = pParams->getCallbackID();
	m_currentCategory = pParams->getCategory();
	m_currentLevel = pParams->getLevel();
	if (strcmp(pParams->getTextureID().c_str(), "lvl_lock") == 0)
	{
		isLock = true;
	}
	m_currentFrame = MOUSE_OUT;
}

void LevelButton::draw()
{
	SDLGameObject::draw();
}

void LevelButton::update()
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

			if (!isLock) 
			{
				m_callback(m_currentCategory, m_currentLevel); // call our callback function
			}
		
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

void LevelButton::clean()
{
	SDLGameObject::clean();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++