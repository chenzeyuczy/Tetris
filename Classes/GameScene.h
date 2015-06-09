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
	void addMenu();
	void addGameArea();

	void switchScene(Ref* pSender);
	void playOrPause(Ref* pSender);
	void restart(Ref* pSender);

	void changeDirection(Ref* pSender);
	void moveDown(Ref* pSender);
	void moveLeft(Ref* pSender);
	void moveRight(Ref* pSender);

	Vec2 positionConvert(Vec2 pos, bool flag);

private:
	Size visibleSize;
	int row, col;
	float blockWidth;
	Layer* gameArea;

	int score, record, level;
	Map<int, Sprite*> status;
};

#endif