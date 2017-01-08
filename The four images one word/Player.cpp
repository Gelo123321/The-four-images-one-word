//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Player.h"
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Player* Player::s_pInstance = 0;


void Player::load(const LoaderParams * pParams)
{
	SDLGameObject::load(pParams);
}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{

}

void Player::clean()
{

}

void Player::setProgress(std::string key, int value)
{
	m_categoryProgress[key] = value;
}

int Player::getProgress(std::string key)
{
	if (!m_categoryProgress[key])
	{
		return 0;
	}

	return m_categoryProgress[key];
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++