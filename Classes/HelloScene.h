#ifndef _HELLOSCENE_H_
#define _HELLOSCENE_H_

#include "cocos2d.h"

USING_NS_CC;

class HelloScene: public Layer
{
public:
	static cocos2d::Scene* createScene();
	CREATE_FUNC(HelloScene);

	virtual bool init();
	void addMenu();
	void switchScene(Ref* pSender);
	void exit(Ref* pSender);

private:
	Size visibleSize;
};

#endif