#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "cocos2d.h"

USING_NS_CC;

class GameScene : public Layer
{
public:
	static cocos2d::Scene* createScene();
	CREATE_FUNC(GameScene);

	virtual bool init();

private:
	Size visibleSize;
};

#endif