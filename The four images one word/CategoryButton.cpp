//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "CategoryButton.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

CategoryButton::CategoryButton() : SDLGameObject()
{
	isLock = false;
}

void CategoryButton::load(const LoaderParams * pParams)
{
	SDLGameObject::load(pParams);
	m_callbackID = pParams->getCallbackID();
	m_currentCategory = pParams->getCategory();
	if (strcmp(pParams->getTextureID().c_str(), "category_lock") == 0)
	{
		isLock = true;
	}
	m_currentFrame = MOUSE_OUT;
}

void CategoryButton::draw()
{
	SDLGameObject::draw();
}

void CategoryButton::update()
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
				m_callback(m_currentCategory); // call our callback function
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

void CategoryButton::clean()
{
	SDLGameObject::clean();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++