//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Gelo123321 - 2016. +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef ANIMATEDGRAPHIC_H
#define ANIMATEDGRAPHIC_H

#include <iostream>
#include "SDL.h"
#include "SDLGameObject.h"
#include "GameObjectFactory.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class AnimatedGraphic : public SDLGameObject
{
public:
	AnimatedGraphic();

	void AnimatedGraphic::load(const LoaderParams *pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	int m_animSpeed;
};

// for the factory
class AnimatedGraphicCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new AnimatedGraphic();
	}
};
#endif
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++