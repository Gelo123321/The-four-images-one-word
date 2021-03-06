//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "SDL.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "GameObjectFactory.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Player : public SDLGameObject
{
public:
	static Player* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Player();
			return s_pInstance;
		}

		return s_pInstance;
	}

	void setProgress(std::string, int);
	int getProgress(std::string);
	
	void load(const LoaderParams *pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
private:

	Player() {};
	~Player() {};

	std::map<std::string, int> m_categoryProgress;

	static Player* s_pInstance;
};

typedef Player ThePlayer;

#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++